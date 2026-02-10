package ti;

import java.io.FileInputStream;
import java.util.zip.ZipInputStream;
import java.util.zip.ZipEntry;
import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.BufferedOutputStream;
import java.io.File;

public class SAFELY_EXTRACT_FILES_FROM_ZIPINPUTSTREAM_TestCase {
    static final int BUFFER = 512;
    static final int TOOBIG = 0x6400000; // max size of unzipped data, 100MB
    static final int TOOMANY = 1024;     // max number of files

    public final void unzip(String filename) throws java.io.IOException{
        FileInputStream fis = null;
        FileOutputStream fos = null;
        try {
            fis = new FileInputStream(filename); /* BUG */ // DO_NOT_OPERATE_ON_FILES_IN_SHARED_DIRECTORIES
            ZipInputStream zis = new ZipInputStream(new BufferedInputStream(fis));
            ZipEntry entry;
            while ((entry = zis.getNextEntry()) != null) {
                System.out.println("Extracting: " + entry);
                int count;
                byte data[] = new byte[BUFFER];
                // Write the files to the disk
                fos = new FileOutputStream(entry.getName()); /* BUG */
                BufferedOutputStream dest = new BufferedOutputStream(fos, BUFFER);
                while ((count = zis.read(data, 0, BUFFER)) != -1) {
                    dest.write(data, 0, count);
                }
                dest.flush();
                dest.close();
                zis.closeEntry();
            }
        } finally {
            if(fis != null) fis.close();
            if(fos != null) fos.close();
        }
    }

    private String validateFilename(String filename, String intendedDir) throws java.io.IOException {
        File f = new File(filename);
        String canonicalPath = f.getCanonicalPath();

        File iD = new File(intendedDir);
        String canonicalID = iD.getCanonicalPath();

        if (canonicalPath.startsWith(canonicalID)) {
            return canonicalPath;
        } else {
            throw new IllegalStateException("File is outside extraction target directory.");
        }
    }

    public final void unzipSafe(String filename) throws java.io.IOException{
        FileInputStream fis = new FileInputStream(filename); /* BUG */ // DO_NOT_OPERATE_ON_FILES_IN_SHARED_DIRECTORIES
        FileOutputStream fos = null;
        ZipInputStream zis = new ZipInputStream(new BufferedInputStream(fis));
        ZipEntry entry;
        int entries = 0;
        int total = 0;
        try {
            while ((entry = zis.getNextEntry()) != null) {
                System.out.println("Extracting: " + entry);
                int count;
                byte data[] = new byte[BUFFER];
                // Write the files to the disk, but ensure that the filename is valid,
                // and that the file is not insanely big
                String name = validateFilename(entry.getName(), ".");
                fos = new FileOutputStream(name);
                BufferedOutputStream dest = new BufferedOutputStream(fos, BUFFER);
                while (total <= TOOBIG && (count = zis.read(data, 0, BUFFER)) != -1) {
                    dest.write(data, 0, count);
                    total += count;
                }
                dest.flush();
                dest.close();
                zis.closeEntry();
                entries++;
                if (entries > TOOMANY) {
                    throw new IllegalStateException("Too many files to unzip.");
                }
                if (total > TOOBIG) {
                    throw new IllegalStateException("File being unzipped is too big.");
                }
            }
        } finally {
            zis.close();
            if(fis != null) fis.close();
            if(fos != null) fos.close();
        }
    }
}

package security;

import java.io.File;
import android.os.ParcelFileDescriptor;
import android.net.Uri;

public class CanonicalizeUrlReceivedByProvider {

    private static File localFile = new File("test");
    private static String IMAGE_DIRECTORY = localFile.getAbsolutePath();

    @Override
    public android.os.ParcelFileDescriptor openFile(Uri paramUri, String paramString)
            throws FileNotFoundException {
        File file = new File(IMAGE_DIRECTORY, paramUri.getLastPathSegment());
        return ParcelFileDescriptor.open(file, ParcelFileDescriptor.MODE_READ_ONLY); // @violation
    }
}
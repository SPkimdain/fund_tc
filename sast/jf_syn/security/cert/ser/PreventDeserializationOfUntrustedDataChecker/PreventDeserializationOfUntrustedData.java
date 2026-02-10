package security;

import java.io.*;
import java.util.*;

class WhitelistedObjectInputStream extends ObjectInputStream {
    public Set whitelist;
    public WhitelistedObjectInputStream(InputStream inputStream, Set wl)
            throws IOException {
        super(inputStream);
        whitelist = wl;
    }

    @Override
    protected Class<?> resolveClass(ObjectStreamClass cls) throws IOException, ClassNotFoundException {
        if (!whitelist.contains(cls.getName())) {
            throw new InvalidClassException("Unexpected serialized class", cls.getName());
        }
        return super.resolveClass(cls);
    }
}

class GoodDeserializeExample {
    private static Object deserialize(byte[] buffer) throws IOException,
            ClassNotFoundException {
        Object ret = null;
        Set whitelist = new HashSet<String>(Arrays.asList(new String[] {
                "GoodClass1",
                "GoodClass2"
        }));
        try (ByteArrayInputStream bais = new ByteArrayInputStream(buffer)) {
            try (WhitelistedObjectInputStream ois = new WhitelistedObjectInputStream(bais, whitelist)) {
                ret = ois.readObject();
            }
        }
        return ret;
    }
}

class BadDeserializeExample {
    public static Object deserialize(byte[] buffer) throws IOException,
            ClassNotFoundException {
        Object ret = null;
        try (ByteArrayInputStream bais = new ByteArrayInputStream(buffer)) {
            try (ObjectInputStream ois = new ObjectInputStream(bais)) {
                ret = ois.readObject(); // @violation
            }
        }
        return ret;
    }
}
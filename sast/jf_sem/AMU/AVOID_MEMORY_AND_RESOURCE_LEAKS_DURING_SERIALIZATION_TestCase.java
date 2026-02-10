package amu;

import java.io.ObjectOutputStream;
import java.io.FileOutputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;

class SensorData {
    public static SensorData readSensorData() { return new SensorData(); }
    public static boolean isAvailable() { return true; }
}

class AVOID_MEMORY_AND_RESOURCE_LEAKS_DURING_SERIALIZATION_TestCase {
    void test1() throws IOException {
        ObjectOutputStream out = null;
        try {
            out = new ObjectOutputStream(
                    new BufferedOutputStream(new FileOutputStream("ser.dat")));
            while (SensorData.isAvailable()) {
                // note that each SensorData object is 1 MB in size
                SensorData sd = SensorData.readSensorData();
                out.writeObject(sd); /* BUG */    // AVOID_MEMORY_AND_RESOURCE_LEAKS_DURING_SERIALIZATION
            }
        } finally {
            if (out != null) {
                out.close();
            }
        }
    }

    void test2() throws IOException {
        ObjectOutputStream out = null;
        try {
            out = new ObjectOutputStream(
                    new BufferedOutputStream(new FileOutputStream("ser.dat")));
            SensorData sd = SensorData.readSensorData();
            while (SensorData.isAvailable()) {
                out.writeObject(sd);
            }
        } finally {
            if (out != null) {
                out.close();
            }
        }
    }

    void testSafe() throws IOException {
        ObjectOutputStream out = null;
        try {
            out = new ObjectOutputStream(
                    new BufferedOutputStream(new FileOutputStream("ser.dat")));
            while (SensorData.isAvailable()) {
                // note that each SensorData object is 1 MB in size
                SensorData sd = SensorData.readSensorData();
                out.writeObject(sd);
                out.reset();
            }
        } finally {
            if (out != null) {
                out.close();
            }
        }
    }
}
package com.example.caig.opencv_test;

/**
 * Interfaces between native C++ code and Java code.
 * <p/>
 * Note that these are the functions that call into native code, native code is
 * responsible for the communication between the application and Tango Service.
 */
public class JniNative {
    static {
        System.loadLibrary("test_proj");
    }

    public static native void cannyEdge(long inputMat, long outputMat);
}

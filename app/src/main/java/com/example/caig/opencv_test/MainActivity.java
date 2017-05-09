package com.example.caig.opencv_test;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceView;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.CvType;
import org.opencv.core.Mat;

// OpenCV Classes

@SuppressWarnings("ALL")
public class MainActivity extends Activity implements CameraBridgeViewBase.CvCameraViewListener2 {

    private static final String TAG = "";
    JavaCameraView javaCameraView;

    Mat mRgba;
    Mat mIntermediateMat;
    Mat mOutput;

    private Mat foreground = new Mat();

    Button btn1, btn2;
    int mode = 0;
    TextView mode_show;

    public native int[] gray(int[] buf, int w, int h);

    static {
        if (!OpenCVLoader.initDebug())
            Log.e(TAG, "Failed to load OpenCV!");
    }

    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                {
                    Log.i(TAG, "OpenCV loaded successfully");
                    javaCameraView.enableView();
                } break;
                default:
                    super.onManagerConnected(status);
                    break;
            }
        }
    };

    private OnClickListener ClickIntHere = new OnClickListener() {
        @Override
        //按下Button事件時會進入這個 function
        public void onClick(View v) {
            if(v.getId() == btn1.getId()) {
                mode = 0;
                mode_show.setText("ORIGINAL");
            }
            else {
                mode = 1;
                mode_show.setText("CANNY EDGE");
            }
        }
    };

    @Override
    protected void onCreate (Bundle saveInstanceState) {
        super.onCreate(saveInstanceState);
        setContentView(R.layout.activity_main);
        javaCameraView = (JavaCameraView)findViewById(R.id.camera_view);
        javaCameraView.setVisibility(SurfaceView.VISIBLE);
        javaCameraView.setCvCameraViewListener(this);

        btn1 = (Button)findViewById(R.id.origin);
        btn2 = (Button)findViewById(R.id.canny);
        btn1.setOnClickListener(ClickIntHere);
        btn2.setOnClickListener(ClickIntHere);

        mode_show = (TextView)findViewById(R.id.mode);
    }

    @Override
    protected void onPause() {
        super.onPause();
        if(javaCameraView.isEnabled()) {
            javaCameraView.disableView();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    public void onCameraViewStarted(int width, int height) {
        mRgba = new Mat(height, width, CvType.CV_8UC4);
        mIntermediateMat = new Mat(height, width, CvType.CV_8UC4);
        mOutput = new Mat(height, width, CvType.CV_8UC4);
    }

    @Override
    public void onCameraViewStopped() {
        mRgba.release();
        mOutput.release();
        mIntermediateMat.release();
    }

    Boolean update_bg_model = true;

    @Override
    public Mat onCameraFrame(CameraBridgeViewBase.CvCameraViewFrame inputFrame) {

        switch(mode) {
            case 0:
                mOutput = inputFrame.rgba();
                break;

            case 1:
            // canny edge
                mRgba = inputFrame.rgba();
                JniNative.cannyEdge(mRgba.getNativeObjAddr(), mIntermediateMat.getNativeObjAddr());
                mOutput = mIntermediateMat.clone();
                break;
        }
        return mOutput;
    }
}
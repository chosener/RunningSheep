/*
 * Copyright (C) 2006 The Android Open Source Project
 * Copyright (c) 2014 Chukong Technologies Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.cocos2dx.lib;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.AssetFileDescriptor;
import android.content.res.Resources;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnErrorListener;
import android.net.Uri;
import android.util.Log;
<<<<<<< HEAD
import android.view.Gravity;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.FrameLayout;
import android.widget.MediaController.MediaPlayerControl;

import java.io.IOException;
import java.util.Map;

<<<<<<< HEAD
import com.chukong.cocosplay.client.CocosPlayClient;

public class Cocos2dxVideoView extends SurfaceView implements MediaPlayerControl {
    private String TAG = "Cocos2dxVideoView";
    
    private Uri         mVideoUri;   
=======
public class Cocos2dxVideoView extends SurfaceView implements MediaPlayerControl {
    private String TAG = "VideoView";
    
    private Uri         mUri;   
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    private int         mDuration;

    // all possible internal states
    private static final int STATE_ERROR              = -1;
    private static final int STATE_IDLE               = 0;
    private static final int STATE_PREPARING          = 1;
    private static final int STATE_PREPARED           = 2;
    private static final int STATE_PLAYING            = 3;
    private static final int STATE_PAUSED             = 4;
    private static final int STATE_PLAYBACK_COMPLETED = 5;

<<<<<<< HEAD
    /**
     * mCurrentState is a VideoView object's current state.
     * mTargetState is the state that a method caller intends to reach.
     * For instance, regardless the VideoView object's current state,
     * calling pause() intends to bring the object to a target state
     * of STATE_PAUSED.
     */
=======
    // mCurrentState is a VideoView object's current state.
    // mTargetState is the state that a method caller intends to reach.
    // For instance, regardless the VideoView object's current state,
    // calling pause() intends to bring the object to a target state
    // of STATE_PAUSED.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    private int mCurrentState = STATE_IDLE;
    private int mTargetState  = STATE_IDLE;

    // All the stuff we need for playing and showing a video
    private SurfaceHolder mSurfaceHolder = null;
    private MediaPlayer mMediaPlayer = null;
    private int         mVideoWidth = 0;
    private int         mVideoHeight = 0;
    
    private OnVideoEventListener mOnVideoEventListener;
    private MediaPlayer.OnPreparedListener mOnPreparedListener;
    private int         mCurrentBufferPercentage;
    private OnErrorListener mOnErrorListener;
    
    // recording the seek position while preparing
    private int         mSeekWhenPrepared;  

    protected Cocos2dxActivity mCocos2dxActivity = null;
    
    protected int mViewLeft = 0;
    protected int mViewTop = 0;
    protected int mViewWidth = 0;
    protected int mViewHeight = 0;
    
    protected int mVisibleLeft = 0;
    protected int mVisibleTop = 0;
    protected int mVisibleWidth = 0;
    protected int mVisibleHeight = 0;
    
    protected boolean mFullScreenEnabled = false;
    protected int mFullScreenWidth = 0;
    protected int mFullScreenHeight = 0;
    
    private int mViewTag = 0;
    
    public Cocos2dxVideoView(Cocos2dxActivity activity,int tag) {
        super(activity);
        
        mViewTag = tag;
        mCocos2dxActivity = activity;
        initVideoView();
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
<<<<<<< HEAD
        if (mVideoWidth == 0 || mVideoHeight == 0) {
            setMeasuredDimension(mViewWidth, mViewHeight);
            Log.i(TAG, ""+mViewWidth+ ":" +mViewHeight);
        }
        else {
            setMeasuredDimension(mVisibleWidth, mVisibleHeight);
            Log.i(TAG, ""+mVisibleWidth+ ":" +mVisibleHeight);
        }
        
    }
    
    public void setVideoRect(int left, int top, int maxWidth, int maxHeight) {
        mViewLeft = left;
        mViewTop = top;
        mViewWidth = maxWidth;
        mViewHeight = maxHeight;
        
        fixSize(mViewLeft, mViewTop, mViewWidth, mViewHeight);
    }
    
    public void setFullScreenEnabled(boolean enabled, int width, int height) {
        if (mFullScreenEnabled != enabled) {
            mFullScreenEnabled = enabled;
            if (width != 0 && height != 0) {
                mFullScreenWidth = width;
                mFullScreenHeight = height;
            }
            
            fixSize();
        }
    }
=======
    	if (mVideoWidth == 0 || mVideoHeight == 0) {
    		setMeasuredDimension(mViewWidth, mViewHeight);
    		Log.i(TAG, ""+mViewWidth+ ":" +mViewHeight);
		}
        else {
        	setMeasuredDimension(mVisibleWidth, mVisibleHeight);
        	Log.i(TAG, ""+mVisibleWidth+ ":" +mVisibleHeight);
		}
    	
    }
    
    public void setVideoRect(int left,int top,int maxWidth,int maxHeight) {
    	mViewLeft = left;
		mViewTop = top;
		mViewWidth = maxWidth;
		mViewHeight = maxHeight;
		
		if (mVideoWidth != 0 && mVideoHeight != 0) {
			fixSize(mViewLeft, mViewTop, mViewWidth, mVideoHeight);
		}
	}
    
    public void setFullScreenEnabled(boolean enabled, int width, int height) {
		if (mFullScreenEnabled != enabled) {
			mFullScreenEnabled = enabled;
			if (width != 0 && height != 0) {
				mFullScreenWidth = width;
				mFullScreenHeight = height;
			}
			
			fixSize();
		}
	}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    public int resolveAdjustedSize(int desiredSize, int measureSpec) {
        int result = desiredSize;
        int specMode = MeasureSpec.getMode(measureSpec);
        int specSize =  MeasureSpec.getSize(measureSpec);

        switch (specMode) {
            case MeasureSpec.UNSPECIFIED:
                /* Parent says we can be as big as we want. Just don't be larger
                 * than max size imposed on ourselves.
                 */
                result = desiredSize;
                break;

            case MeasureSpec.AT_MOST:
                /* Parent says we can be as big as we want, up to specSize.
                 * Don't be larger than specSize, and don't be larger than
                 * the max size imposed on ourselves.
                 */
                result = Math.min(desiredSize, specSize);
                break;

            case MeasureSpec.EXACTLY:
                // No choice. Do what we are told.
                result = specSize;
                break;
        }
<<<<<<< HEAD
        
        return result;
    }
=======
        return result;
}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    private boolean mNeedResume = false;
    
    @Override
    public void setVisibility(int visibility) {
<<<<<<< HEAD
        if (visibility == INVISIBLE) {
            mNeedResume = isPlaying();
            if (mNeedResume) {
                mSeekWhenPrepared = getCurrentPosition();
            }
        }
        else if (mNeedResume){
            start();
            mNeedResume = false;
        }
        super.setVisibility(visibility);
=======
    	if (visibility == INVISIBLE) {
			mNeedResume = isPlaying();
			if (mNeedResume) {
				mSeekWhenPrepared = getCurrentPosition();
			}
		}
    	else if (mNeedResume){
    		start();
			mNeedResume = false;
		}
    	super.setVisibility(visibility);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
    
    private void initVideoView() {
        mVideoWidth = 0;
        mVideoHeight = 0;
        getHolder().addCallback(mSHCallback);
<<<<<<< HEAD
        //Fix issue#11516:Can't play video on Android 2.3.x
        getHolder().setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setFocusable(true);
        setFocusableInTouchMode(true);
        mCurrentState = STATE_IDLE;
        mTargetState  = STATE_IDLE;
    }
    
    @Override
    public boolean onTouchEvent(MotionEvent event) {
<<<<<<< HEAD
        if((event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP)
        {
            if (isPlaying()) {
                pause();
            } else if(mCurrentState == STATE_PAUSED){
                resume();
            }
        }
        
        return true;
    }
    
    private boolean mIsAssetRouse = false;
    private String mVideoFilePath = null;
    private static final String AssetResourceRoot = "assets/";
    
    public void setVideoFileName(String path) {
        if (path.startsWith(AssetResourceRoot)) {
            path = path.substring(AssetResourceRoot.length());
        }
        if (CocosPlayClient.isEnabled() && !CocosPlayClient.isDemo()) {
            CocosPlayClient.updateAssets(path);
        }
        CocosPlayClient.notifyFileLoaded(path);
        if (path.startsWith("/")) {
            mIsAssetRouse = false;
            setVideoURI(Uri.parse(path),null);
        }
        else {
            mVideoFilePath = path;
            mIsAssetRouse = true;
            setVideoURI(Uri.parse(path),null);
        }
    }
    
    public void setVideoURL(String url) {
        mIsAssetRouse = false;
        setVideoURI(Uri.parse(url), null);
=======
    	if((event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP)
    	{
    		if (isPlaying()) {
    			pause();
    		} else if(mCurrentState == STATE_PAUSED){
    			resume();
    		}
    	}
    	
    	return true;
    }
    
    private boolean isAssetRouse = false;
    private String fileName = null;
    
    public void setVideoFileName(String path) {
    	if (path.startsWith("/")) {
    		isAssetRouse = false;
			setVideoURI(Uri.parse(path),null);
		}
		else {
			fileName = path;
			isAssetRouse = true;
			setVideoURI(Uri.parse(path),null);
		}
    }
    
    public void setVideoURL(String url) {
    	isAssetRouse = false;
    	setVideoURI(Uri.parse(url), null);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }

    /**
     * @hide
     */
    private void setVideoURI(Uri uri, Map<String, String> headers) {
<<<<<<< HEAD
        mVideoUri = uri;
=======
        mUri = uri;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        mSeekWhenPrepared = 0;
        mVideoWidth = 0;
        mVideoHeight = 0;
        openVideo();
        requestLayout();
        invalidate();
    }
    
    public void stopPlayback() {
        if (mMediaPlayer != null) {
            mMediaPlayer.stop();
            mMediaPlayer.release();
            mMediaPlayer = null;
            mCurrentState = STATE_IDLE;
            mTargetState  = STATE_IDLE;
        }
    }

    private void openVideo() {
<<<<<<< HEAD
        if (mSurfaceHolder == null) {
            // not ready for playback just yet, will try again later
            return;
        }
        if (mIsAssetRouse) {
            if(mVideoFilePath == null)
                return;
        } else if(mVideoUri == null) {
            return;
        }
=======
    	if (mSurfaceHolder == null) {
    		// not ready for playback just yet, will try again later
			return;
		}
    	if (isAssetRouse) {
			if(fileName == null)
				return;
		} else {
			if(mUri == null)
				return;
		}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        // Tell the music playback service to pause
        // TODO: these constants need to be published somewhere in the framework.
        Intent i = new Intent("com.android.music.musicservicecommand");
        i.putExtra("command", "pause");
        mCocos2dxActivity.sendBroadcast(i);

        // we shouldn't clear the target state, because somebody might have
        // called start() previously
        release(false);
        
        try {
<<<<<<< HEAD
            //if (mMediaPlayer == null) {
                mMediaPlayer = new MediaPlayer();
=======
        	//if (mMediaPlayer == null) {
        		mMediaPlayer = new MediaPlayer();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
                mMediaPlayer.setOnPreparedListener(mPreparedListener);
                mMediaPlayer.setOnVideoSizeChangedListener(mSizeChangedListener);                
                mMediaPlayer.setOnCompletionListener(mCompletionListener);
                mMediaPlayer.setOnErrorListener(mErrorListener);
                mMediaPlayer.setOnBufferingUpdateListener(mBufferingUpdateListener);
                
                mMediaPlayer.setDisplay(mSurfaceHolder);
                mMediaPlayer.setAudioStreamType(AudioManager.STREAM_MUSIC);
                mMediaPlayer.setScreenOnWhilePlaying(true);
<<<<<<< HEAD
            //}
            
            mDuration = -1;
            mCurrentBufferPercentage = 0;
            if (mIsAssetRouse) {
                AssetFileDescriptor afd = mCocos2dxActivity.getAssets().openFd(mVideoFilePath);
                mMediaPlayer.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(),afd.getLength());
            } else {
                mMediaPlayer.setDataSource(mCocos2dxActivity, mVideoUri);
            }
            
            mMediaPlayer.prepareAsync();

            /**
             * Don't set the target state here either, but preserve the target state that was there before.
             */
            mCurrentState = STATE_PREPARING;
        } catch (IOException ex) {
            Log.w(TAG, "Unable to open content: " + mVideoUri, ex);
=======
			//}
        	
        	mDuration = -1;
            mCurrentBufferPercentage = 0;
            if (isAssetRouse) {
            	AssetFileDescriptor afd = mCocos2dxActivity.getAssets().openFd(fileName);
            	mMediaPlayer.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(),afd.getLength());
			} else {
				mMediaPlayer.setDataSource(mCocos2dxActivity, mUri);
			}
            
            mMediaPlayer.prepareAsync();
            // we don't set the target state here either, but preserve the
            // target state that was there before.
            mCurrentState = STATE_PREPARING;
        } catch (IOException ex) {
            Log.w(TAG, "Unable to open content: " + mUri, ex);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            mCurrentState = STATE_ERROR;
            mTargetState = STATE_ERROR;
            mErrorListener.onError(mMediaPlayer, MediaPlayer.MEDIA_ERROR_UNKNOWN, 0);
            return;
        } catch (IllegalArgumentException ex) {
<<<<<<< HEAD
            Log.w(TAG, "Unable to open content: " + mVideoUri, ex);
=======
            Log.w(TAG, "Unable to open content: " + mUri, ex);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            mCurrentState = STATE_ERROR;
            mTargetState = STATE_ERROR;
            mErrorListener.onError(mMediaPlayer, MediaPlayer.MEDIA_ERROR_UNKNOWN, 0);
            return;
        }
    }
    
    private boolean mKeepRatio = false;
    
    public void setKeepRatio(boolean enabled) {
<<<<<<< HEAD
        mKeepRatio = enabled;
        fixSize();
    }

    public void fixSize() {
        if (mFullScreenEnabled) {
            fixSize(0, 0, mFullScreenWidth, mFullScreenHeight);
        } else {
            fixSize(mViewLeft, mViewTop, mViewWidth, mViewHeight);
        }
    }
    
    public void fixSize(int left, int top, int width, int height) {
        if (mVideoWidth == 0 || mVideoHeight == 0) {
            mVisibleLeft = left;
            mVisibleTop = top;
            mVisibleWidth = width;
            mVisibleHeight = height;
        }
        else if (width != 0 && height != 0) {
            if (mKeepRatio) {
                if ( mVideoWidth * height  > width * mVideoHeight ) {
                    mVisibleWidth = width;
                    mVisibleHeight = width * mVideoHeight / mVideoWidth;
                } else if ( mVideoWidth * height  < width * mVideoHeight ) {
                    mVisibleWidth = height * mVideoWidth / mVideoHeight;
                    mVisibleHeight = height;
                }
                mVisibleLeft = left + (width - mVisibleWidth) / 2;
                mVisibleTop = top + (height - mVisibleHeight) / 2;
            } else {
                mVisibleLeft = left;
                mVisibleTop = top;
                mVisibleWidth = width;
                mVisibleHeight = height;
            }
        }
        else {
            mVisibleLeft = left;
            mVisibleTop = top;
            mVisibleWidth = mVideoWidth;
            mVisibleHeight = mVideoHeight;
        }
        
        getHolder().setFixedSize(mVisibleWidth, mVisibleHeight);
        
        FrameLayout.LayoutParams lParams = new FrameLayout.LayoutParams(FrameLayout.LayoutParams.WRAP_CONTENT,
                FrameLayout.LayoutParams.WRAP_CONTENT);
        lParams.leftMargin = mVisibleLeft;
        lParams.topMargin = mVisibleTop;
        lParams.gravity = Gravity.TOP | Gravity.LEFT;
        setLayoutParams(lParams);
    }
=======
    	mKeepRatio = enabled;
    	fixSize();
	}

    public void fixSize() {
    	if (mFullScreenEnabled) {
			fixSize(0, 0, mFullScreenWidth, mFullScreenHeight);
		} else {
			fixSize(mViewLeft, mViewTop, mViewWidth, mVideoHeight);
		}
	}
    
    public void fixSize(int left,int top,int width,int height) {
    	if (width != 0 && height != 0) {
    		if (mKeepRatio) {
    			if ( mVideoWidth * height  > width * mVideoHeight ) {
    				mVisibleWidth = width;
    				mVisibleHeight = width * mVideoHeight / mVideoWidth;
                } else if ( mVideoWidth * height  < width * mVideoHeight ) {
                	mVisibleWidth = height * mVideoWidth / mVideoHeight;
                	mVisibleHeight = height;
                }
    			mVisibleLeft = left + (width - mVisibleWidth) / 2;
    			mVisibleTop = top + (height - mVisibleHeight) / 2;
			} else {
				mVisibleLeft = left;
	    		mVisibleTop = top;
				mVisibleWidth = width;
				mVisibleHeight = height;
			}
		}
    	else {
    		mVisibleLeft = left;
    		mVisibleTop = top;
			mVisibleWidth = mVideoWidth;
			mVisibleHeight = mVideoHeight;
		}
    	
    	getHolder().setFixedSize(mVisibleWidth, mVisibleHeight);
    	
    	FrameLayout.LayoutParams lParams = new FrameLayout.LayoutParams(FrameLayout.LayoutParams.WRAP_CONTENT,
				FrameLayout.LayoutParams.WRAP_CONTENT);
		lParams.leftMargin = mVisibleLeft;
		lParams.topMargin = mVisibleTop;
		setLayoutParams(lParams);
	}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    protected 
    MediaPlayer.OnVideoSizeChangedListener mSizeChangedListener =
        new MediaPlayer.OnVideoSizeChangedListener() {
            public void onVideoSizeChanged(MediaPlayer mp, int width, int height) {
                mVideoWidth = mp.getVideoWidth();
                mVideoHeight = mp.getVideoHeight();
                if (mVideoWidth != 0 && mVideoHeight != 0) {
                    getHolder().setFixedSize(mVideoWidth, mVideoHeight);
                }
            }
    };
    

    MediaPlayer.OnPreparedListener mPreparedListener = new MediaPlayer.OnPreparedListener() {
        public void onPrepared(MediaPlayer mp) {
            mCurrentState = STATE_PREPARED;

            if (mOnPreparedListener != null) {
                mOnPreparedListener.onPrepared(mMediaPlayer);
            }
            
            mVideoWidth = mp.getVideoWidth();
            mVideoHeight = mp.getVideoHeight();

<<<<<<< HEAD
            // mSeekWhenPrepared may be changed after seekTo() call
            int seekToPosition = mSeekWhenPrepared;  
            if (seekToPosition != 0) {
                seekTo(seekToPosition);
            }
            
            if (mVideoWidth != 0 && mVideoHeight != 0) {
                fixSize();
=======
            int seekToPosition = mSeekWhenPrepared;  // mSeekWhenPrepared may be changed after seekTo() call
            if (seekToPosition != 0) {
                seekTo(seekToPosition);
            }
            if (mVideoWidth != 0 && mVideoHeight != 0) {
            	fixSize();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            } 
            
            if (mTargetState == STATE_PLAYING) {
                start();
            }
        }
    };

    private MediaPlayer.OnCompletionListener mCompletionListener =
        new MediaPlayer.OnCompletionListener() {
        public void onCompletion(MediaPlayer mp) {
            mCurrentState = STATE_PLAYBACK_COMPLETED;
            mTargetState = STATE_PLAYBACK_COMPLETED;
            
            release(true);
            if (mOnVideoEventListener != null) {
                mOnVideoEventListener.onVideoEvent(mViewTag,EVENT_COMPLETED);
            }
        }
    };
    
    
    private static final int EVENT_PLAYING = 0;
    private static final int EVENT_PAUSED = 1;
    private static final int EVENT_STOPPED = 2;
    private static final int EVENT_COMPLETED = 3;
    
    public interface OnVideoEventListener
    {
<<<<<<< HEAD
        void onVideoEvent(int tag,int event);
=======
    	void onVideoEvent(int tag,int event);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }

    private MediaPlayer.OnErrorListener mErrorListener =
        new MediaPlayer.OnErrorListener() {
        public boolean onError(MediaPlayer mp, int framework_err, int impl_err) {
            Log.d(TAG, "Error: " + framework_err + "," + impl_err);
            mCurrentState = STATE_ERROR;
            mTargetState = STATE_ERROR;

            /* If an error handler has been supplied, use it and finish. */
            if (mOnErrorListener != null) {
                if (mOnErrorListener.onError(mMediaPlayer, framework_err, impl_err)) {
                    return true;
                }
            }

            /* Otherwise, pop up an error dialog so the user knows that
             * something bad has happened. Only try and pop up the dialog
             * if we're attached to a window. When we're going away and no
             * longer have a window, don't bother showing the user an error.
             */
            if (getWindowToken() != null) {
                Resources r = mCocos2dxActivity.getResources();
                int messageId;
                
                if (framework_err == MediaPlayer.MEDIA_ERROR_NOT_VALID_FOR_PROGRESSIVE_PLAYBACK) {
<<<<<<< HEAD
                    // messageId = com.android.internal.R.string.VideoView_error_text_invalid_progressive_playback;
                    messageId = r.getIdentifier("VideoView_error_text_invalid_progressive_playback", "string", "android");
                } else {
                    // messageId = com.android.internal.R.string.VideoView_error_text_unknown;
                    messageId = r.getIdentifier("VideoView_error_text_unknown", "string", "android");
=======
                    //messageId = com.android.internal.R.string.VideoView_error_text_invalid_progressive_playback;
                	messageId = r.getIdentifier("VideoView_error_text_invalid_progressive_playback", "string", "android");
                } else {
                    //messageId = com.android.internal.R.string.VideoView_error_text_unknown;
                	messageId = r.getIdentifier("VideoView_error_text_unknown", "string", "android");
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
                }
                
                int titleId = r.getIdentifier("VideoView_error_title", "string", "android");
                int buttonStringId = r.getIdentifier("VideoView_error_button", "string", "android");
                
                new AlertDialog.Builder(mCocos2dxActivity)
                        .setTitle(r.getString(titleId))
                        .setMessage(messageId)
                        .setPositiveButton(r.getString(buttonStringId),
                                new DialogInterface.OnClickListener() {
                                    public void onClick(DialogInterface dialog, int whichButton) {
                                        /* If we get here, there is no onError listener, so
                                         * at least inform them that the video is over.
                                         */
                                        if (mOnVideoEventListener != null) {
                                            mOnVideoEventListener.onVideoEvent(mViewTag,EVENT_COMPLETED);
                                        }
                                    }
                                })
                        .setCancelable(false)
                        .show();
            }
            return true;
        }
    };

    private MediaPlayer.OnBufferingUpdateListener mBufferingUpdateListener =
        new MediaPlayer.OnBufferingUpdateListener() {
        public void onBufferingUpdate(MediaPlayer mp, int percent) {
            mCurrentBufferPercentage = percent;
        }
    };

    /**
     * Register a callback to be invoked when the media file
     * is loaded and ready to go.
     *
     * @param l The callback that will be run
     */
    public void setOnPreparedListener(MediaPlayer.OnPreparedListener l)
    {
        mOnPreparedListener = l;
    }

    /**
     * Register a callback to be invoked when the end of a media file
<<<<<<< HEAD
     * has been reached during play back.
=======
     * has been reached during playback.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @param l The callback that will be run
     */
    public void setOnCompletionListener(OnVideoEventListener l)
    {
        mOnVideoEventListener = l;
    }

    /**
     * Register a callback to be invoked when an error occurs
<<<<<<< HEAD
     * during play back or setup.  If no listener is specified,
=======
     * during playback or setup.  If no listener is specified,
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * or if the listener returned false, VideoView will inform
     * the user of any errors.
     *
     * @param l The callback that will be run
     */
    public void setOnErrorListener(OnErrorListener l)
    {
        mOnErrorListener = l;
    }

    SurfaceHolder.Callback mSHCallback = new SurfaceHolder.Callback()
    {
        public void surfaceChanged(SurfaceHolder holder, int format,
                                    int w, int h)
        {
            boolean isValidState =  (mTargetState == STATE_PLAYING);
            boolean hasValidSize = (mVideoWidth == w && mVideoHeight == h);
            if (mMediaPlayer != null && isValidState && hasValidSize) {
                if (mSeekWhenPrepared != 0) {
                    seekTo(mSeekWhenPrepared);
                }
                start();
            }
        }

        public void surfaceCreated(SurfaceHolder holder)
        {
            mSurfaceHolder = holder;
            openVideo();
        }

        public void surfaceDestroyed(SurfaceHolder holder)
        {
            // after we return from this we can't use the surface any more
            mSurfaceHolder = null;
            
            release(true);
        }
    };

    /*
     * release the media player in any state
     */
    private void release(boolean cleartargetstate) {
        if (mMediaPlayer != null) {
            mMediaPlayer.reset();
            mMediaPlayer.release();
            mMediaPlayer = null;
            mCurrentState = STATE_IDLE;
            if (cleartargetstate) {
                mTargetState  = STATE_IDLE;
            }
        }
    }
    
    public void start() {
<<<<<<< HEAD
        if (isInPlaybackState()) {
            mMediaPlayer.start();
            mCurrentState = STATE_PLAYING;
            if (mOnVideoEventListener != null) {
                mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_PLAYING);
            }
=======
    	if (isInPlaybackState()) {
            mMediaPlayer.start();
            mCurrentState = STATE_PLAYING;
            if (mOnVideoEventListener != null) {
            	mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_PLAYING);
			}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        mTargetState = STATE_PLAYING;
    }

    public void pause() {
        if (isInPlaybackState()) {
            if (mMediaPlayer.isPlaying()) {
                mMediaPlayer.pause();
                mCurrentState = STATE_PAUSED;
                if (mOnVideoEventListener != null) {
<<<<<<< HEAD
                    mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_PAUSED);
                }
=======
                	mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_PAUSED);
				}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            }
        }
        mTargetState = STATE_PAUSED;
    }
    
    public void stop() {
        if (isInPlaybackState()) {
            if (mMediaPlayer.isPlaying()) {
               stopPlayback();
                if (mOnVideoEventListener != null) {
<<<<<<< HEAD
                    mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_STOPPED);
                }
=======
                	mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_STOPPED);
				}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            }
        }
    }

    public void suspend() {
        release(false);
    }

    public void resume() {
<<<<<<< HEAD
        if (isInPlaybackState()) {
            if (mCurrentState == STATE_PAUSED) {
                mMediaPlayer.start();
                mCurrentState = STATE_PLAYING;
                if (mOnVideoEventListener != null) {
                    mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_PLAYING);
                }
            }
        }
    }

    public void restart() {
        if (isInPlaybackState()) {
            mMediaPlayer.seekTo(0);
            mMediaPlayer.start();
            mCurrentState = STATE_PLAYING;
            mTargetState = STATE_PLAYING;
        }
    }
=======
    	if (isInPlaybackState()) {
    		if (mCurrentState == STATE_PAUSED) {
				mMediaPlayer.start();
				mCurrentState = STATE_PLAYING;
				if (mOnVideoEventListener != null) {
                	mOnVideoEventListener.onVideoEvent(mViewTag, EVENT_PLAYING);
				}
			}
    	}
    }

    public void restart() {
    	if (isInPlaybackState()) {
    		mMediaPlayer.seekTo(0);
    		mMediaPlayer.start();
            mCurrentState = STATE_PLAYING;
    		mTargetState = STATE_PLAYING;
    	}
	}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    // cache duration as mDuration for faster access
    public int getDuration() {
        if (isInPlaybackState()) {
            if (mDuration > 0) {
                return mDuration;
            }
            mDuration = mMediaPlayer.getDuration();
            return mDuration;
        }
        mDuration = -1;
        return mDuration;
    }

    public int getCurrentPosition() {
        if (isInPlaybackState()) {
            return mMediaPlayer.getCurrentPosition();
        }
        return 0;
    }

    public void seekTo(int msec) {
        if (isInPlaybackState()) {
            mMediaPlayer.seekTo(msec);
            mSeekWhenPrepared = 0;
        } else {
            mSeekWhenPrepared = msec;
        }
    }

    public boolean isPlaying() {
        return isInPlaybackState() && mMediaPlayer.isPlaying();
    }

    public int getBufferPercentage() {
        if (mMediaPlayer != null) {
            return mCurrentBufferPercentage;
        }
        return 0;
    }

    public boolean isInPlaybackState() {
        return (mMediaPlayer != null &&
                mCurrentState != STATE_ERROR &&
                mCurrentState != STATE_IDLE &&
                mCurrentState != STATE_PREPARING);
    }

<<<<<<< HEAD
    @Override
    public boolean canPause() {
        return true;
    }

    @Override
    public boolean canSeekBackward() {
        return true;
    }

    @Override
    public boolean canSeekForward() {
        return true;
    }
        
    public int getAudioSessionId () {
=======
	@Override
	public boolean canPause() {
		// TODO Auto-generated method stub
		return true;
	}

	@Override
	public boolean canSeekBackward() {
		// TODO Auto-generated method stub
		return true;
	}

	@Override
	public boolean canSeekForward() {
		// TODO Auto-generated method stub
		return true;
	}
    	
    public int getAudioSessionId () {
       // TODO Auto-generated method stub
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
       return mMediaPlayer.getAudioSessionId();
    }
}

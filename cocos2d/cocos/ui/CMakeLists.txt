<<<<<<< HEAD

if(WINDOWS AND BUILD_SHARED_LIBS)
  ADD_DEFINITIONS (-D_USEGUIDLL)
endif()

if(WINDOWS)
  set(COCOS_UI_SPECIFIC_SRC
      ui/UIEditBox/UIEditBoxImpl-win32.cpp
      )
elseif(MACOSX)
  set(COCOS_UI_SPECIFIC_SRC
      ui/UIEditBox/UIEditBoxImpl-mac.mm
      )
elseif(LINUX)
  set(COCOS_UI_SPECIFIC_SRC
      ui/UIEditBox/UIEditBoxImpl-stub.cpp
      )
endif()

#todo: android UIWebViewImpl and UIVideoPlayer
# will add when doing android support

set(COCOS_UI_SRC

  ui/CocosGUI.cpp
  ui/UIButton.cpp
  ui/UICheckBox.cpp
  ui/UIDeprecated.cpp
=======
set(COCOS_UI_SRC
  ui/CCProtectedNode.cpp
  ui/CocosGUI.cpp
  ui/UIButton.cpp
  ui/UICheckBox.cpp
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
  ui/UIHBox.cpp
  ui/UIHelper.cpp
  ui/UIImageView.cpp
  ui/UILayout.cpp
<<<<<<< HEAD
  ui/UILayoutManager.cpp
  ui/UILayoutParameter.cpp
=======
  ui/UILayoutParameter.cpp
  ui/UILayoutManager.cpp
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
  ui/UIListView.cpp
  ui/UILoadingBar.cpp
  ui/UIPageView.cpp
  ui/UIRelativeBox.cpp
  ui/UIRichText.cpp
<<<<<<< HEAD
  ui/UIScale9Sprite.cpp
  ui/UIScrollView.cpp
  ui/UISlider.cpp
  ui/UIText.cpp
  ui/UITextAtlas.cpp
  ui/UITextBMFont.cpp
  ui/UITextField.cpp
  ui/UIVBox.cpp
  ui/UIWebView.cpp
  ui/UIWidget.cpp
  ui/UIEditBox/UIEditBox.cpp
  ui/UILayoutComponent.cpp
  ${COCOS_UI_SPECIFIC_SRC}

)
=======
  ui/UIScrollView.cpp
  ui/UISlider.cpp
  ui/UITextAtlas.cpp
  ui/UITextBMFont.cpp
  ui/UIText.cpp
  ui/UITextField.cpp
  ui/UIVBox.cpp
  ui/UIWidget.cpp
  ui/UIDeprecated.cpp
)

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

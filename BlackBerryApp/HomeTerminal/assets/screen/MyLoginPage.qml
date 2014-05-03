import bb.cascades 1.2
import bb.system 1.2

NavigationPane {
    id: navigationpane
    attachedObjects: [
        ComponentDefinition {
            id: terminalpage
            source: "asset:///screen/TerminalPage.qml" 
        },
        SystemToast {
            id: notificationtoast          
            onBodyChanged: {
                if(body == "Login success")
                    navigationpane.push(terminalpage.createObject());
            }  
        }
    ]
    Page {
        titleBar: TitleBar {
            title: qsTr("Home Terminal")
        }
        Container {
            id: maincontainer
            layout: DockLayout {
            }    
            Container {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                layout: StackLayout {
                    orientation: LayoutOrientation.TopToBottom
                }
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    horizontalAlignment: HorizontalAlignment.Center
                    ImageView {
                        imageSource: "asset:///image/login.png"
                    }
                    Label {
                        text: qsTr("Terminal Login")
                        textStyle.fontSize: FontSize.XXLarge
                        verticalAlignment: VerticalAlignment.Center
                    }
                }
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    rightPadding: 20.0
                    leftPadding: 20.0
                    topPadding: 20.0
                    Label {
                        text: qsTr("User Name : ")
                        verticalAlignment: VerticalAlignment.Center
                    }
                    TextField {
                        id: userNameTextField
                        text: "sommily"
                        onTextChanging: {
                            if(passwordTextField.text.length >= 8 && userNameTextField.text.length > 0)
                                loginbutton.enabled = true;
                            else 
                                loginbutton.enabled = false;
                        }
                    }
                }
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    leftPadding: 20.0
                    rightPadding: 20.0
                    topPadding: 20.0
                    Label {
                        text: qsTr("Password    : ")
                        verticalAlignment: VerticalAlignment.Center
                    }
                    TextField {
                        id: passwordTextField
                        text: "19920428"
                        inputMode: TextFieldInputMode.Password
                        onTextChanging: {
                            if(passwordTextField.text.length >= 8 && userNameTextField.text.length > 0)
                                loginbutton.enabled = true;
                            else 
                                loginbutton.enabled = false;
                        }
                    }
                }
                Container {
                    layout: DockLayout {
                    }
                    topPadding: 20.0
                    leftPadding: 20.0
                    rightPadding: 20.0
                    horizontalAlignment: HorizontalAlignment.Center
                    preferredWidth: 600.0
                    Button {
                        id: cancelButton
                        text: qsTr("Cancel")
                        imageSource: "asset:///image/ic_cancel.png"
                        horizontalAlignment: HorizontalAlignment.Left
                        preferredWidth: 250.0
                    }
                    Button {
                        id: loginbutton	
                        text: qsTr("Login")
                        enabled: false
                        imageSource: "asset:///image/ic_done.png"
                        horizontalAlignment: HorizontalAlignment.Right
                        preferredWidth: 250.0
                        onClicked: {
                            _mylogin.SendInfo(userNameTextField.text,passwordTextField.text);    
                        }
                    }
                }
            }
            ActivityIndicator {
                id: loginindicator
                running: false
                onRunningChanged: {
                    if(running == false)
                    {
                    	maincontainer.enabled = true;
	                }
                    else 
                    	maincontainer.enabled = false;
                }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                preferredWidth: 300.0
                preferredHeight: 300.0
            }
        }
        onCreationCompleted: {
            _mylogin.Init(loginindicator,notificationtoast);
        }
    }
}
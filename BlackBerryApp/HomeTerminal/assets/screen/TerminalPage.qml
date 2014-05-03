import bb.cascades 1.2

Page {
    Container {
        layout: DockLayout {
        }
        background: Color.Black
        Container {
        	TextArea {
        	    id: commandstextarea
                editable: false
                textStyle.color: Color.White
            }   
        }
        Container {
            verticalAlignment: VerticalAlignment.Bottom
            horizontalAlignment: HorizontalAlignment.Fill
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            leftPadding: 20.0
            rightPadding: 20.0
            bottomPadding: 20.0
            TextField {
                id: commandtextfield
                hintText: qsTr("Enter command")
                textStyle.color: Color.White
                input.submitKey: SubmitKey.Send
                backgroundVisible: false
                inputMode: TextFieldInputMode.Text
                clearButtonVisible: false
                input.onSubmitted: {
                    commandtextfield.text.trim().toLowerCase() != "clear"
                        ?commandstextarea.text = commandtextfield.text + '\n' + commandstextarea.text
                        :commandstextarea.text = '';
                    commandtextfield.text = '';
                }
            }
        }
    }
}
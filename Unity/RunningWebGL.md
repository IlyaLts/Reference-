Firefox (recommended browser for running WebGL)

Type about:config in the navigation bar
Search for the `security.fileuri.strict_origin_policy` parameter
Click that parameter to change it to false

Chrome
Add a shortcut to Chrome on your desktop if you don't have one
Right click the shortcut and select Properties
Select the Target text box, go to the end, add a space and add `--allow-file-access-from-files`
Double-click the index html file for the WebGL build and copy the URL in the navigation bar when the browser opens
Close the browser
Start the browser using the shortcut, paste in the URL you copied in Step 4 and press enter

Microsoft Edge
No need to do anything, WebGL builds work fine.

Safari

Enable the develop menu using the preferences panel, under Advanced → “Show develop menu in menu bar”
From the safari “Develop” menu, select “Disable local file restrictions”
As a general rule, restart your computer after making these changes since browsers require it and some don't.
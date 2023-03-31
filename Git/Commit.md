# Commit

- #### Commit the staged snapshot  
```git commit```

- #### Commit a snapshot of all changes in the working directory  
```git commit -a```

- #### Commit the staged snapshot with a message  
```git commit -m "commit message"```

- #### Commit a snapshot of all changes in the working directory with a message  
```git commit -am "commit message"```

- #### Change the previosly specified commit  
```git commit --amend -m "new commit message"```  or ```git commit --amend --no-edit```  
This option adds another level of functionality to the commit command. Passing this option will modify the last commit. Instead of creating a new commit, staged changes will be added to the previous commit. This command will open up the system's configured text editor and prompt to change the previously specified commit message.

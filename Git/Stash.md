# Stash

The git stash command takes your uncommitted changes (both staged and unstaged), saves them away for later use, and then reverts them from your working copy.
Note that the stash is local to your Git repository; stashes are not transferred to the server when you push.

git stash apply vs pop : They are almost similar except the fact that git stash pop throws away the (topmost, by default) stash when applying it, whereas git stash apply leaves it within the stash list for possible later use (or you'll then git stash drop it)

- #### Stash
```git stash``` or with a message ```git stash -m <message>```

- #### Stash- all changes already added to the index are left intact.
```git stash --keep-index``` or with a message ```git stash --keep-index -m <message>```

- #### Stash with untracked or ignored files  
```git stash -u```

- #### Stash pop  
```git stash pop``` or ```git stash pop stash@{2}```  
By default, git stash pop will re-apply the most recently created stash: stash@{0}

- #### Stash apply  
```git stash apply``` or ```git stash apply stash@{2}```  
By default, git stash pop will re-apply the most recently created stash: stash@{0}

- #### List all stashes  
```git stash list```

- #### Show stash diffs  
```git stash show``` or full diff ```git stash show -p```

- #### Create a branch from stash  
```git stash branch <branchname> <stash>```  
Stash for example: (stash@{1})

- #### Remove a stash  
```git stash drop <stash>```

- #### Remove all stashes  
```git stash clear```

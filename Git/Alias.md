# Alias

- #### Create an alias  
```git config --global alias.st status```

Example:
```
git config --global alias.ci commit
git ci -m "new commit"
```

- #### Using aliases to create new Git commands  
```git config --global alias.unstage 'reset HEAD --'```

Example:
```
git unstage fileA
$ git reset HEAD -- fileA
```

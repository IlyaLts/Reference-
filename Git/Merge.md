# Merge

Join two or more development histories together.

- #### Merge a branch
```git merge <branch>```

- #### Merge a branch with fast forward  
```git merge --ff <branch>```

- #### Merge a branch without fast forward  
```git merge --no-ff <branch>```

- #### Merge a branch with fast forward only  
```git merge --ff-only <branch>```

- #### Merge with squash
```git merge --squash <branch>```  
This is a way of compressing multiple commits into a single commit. It can be done as part of a merge or a rebase operation. It reduces the clutter and noise in the history, but it also loses some information about the individual commits and their authors

- #### Merge with no commit
```git merge --no-commit <branch>```  
With `--no-commit` perform the merge and stop just before creating a merge commit, to give the user a chance to inspect and further tweak the merge result before committing.

Note that fast-forward updates do not create a merge commit and therefore there is no way to stop those merges with `--no-commit`. Thus, if you want to ensure your branch is not changed or updated by the merge command, use `--no-ff` with `--no-commit`.

- #### Abort merge  
```git merge --abort```
Executing git merge with the `--abort` option will exit from the merge process and return the branch to the state before the merge began.

- #### Recursive merge  
```git merge -s recursive <branch1> <branch2>```  
This operates on two heads. Recursive is the default merge strategy when pulling or merging one branch. Additionally this can detect and handle merges involving renames, but currently cannot make use of detected copies. This is the default merge strategy when pulling or merging one branch.

- #### Resolve merge  
```git merge -s resolve <branch1> <branch2>```  
This can only resolve two heads using a 3-way merge algorithm. It tries to carefully detect cris-cross merge ambiguities and is considered generally safe and fast.

- #### Octopus merge  
```git merge -s octopus <branch1> <branch2> <branch3>```  
This can only resolve two heads using a 3-way merge algorithm. It tries to carefully detect cris-cross merge ambiguities and is considered generally safe and fast.

- #### Allow unrelated histories  
```git merge --allow-unrelated-histories <branch>```  
By default, git merge command refuses to merge histories that do not share a common ancestor. This option can be used to override this safety when merging histories of two projects that started their lives independently. As that is a very rare occasion, no configuration variable to enable this by default exists and will not be added.
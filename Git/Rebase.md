# Rebase

Reapply commits on top of another base tip.

- #### Rebase  
```git rebase <base>```
This automatically rebases the current branch onto ＜base＞, which can be any kind of commit reference (for example an ID, a branch name, a tag, or a relative reference to HEAD).

- #### Rebase onto  
```git rebase --onto <newbase> <oldbase>```
The --onto command enables a more powerful form or rebase that allows passing specific refs to be the tips of a rebase.

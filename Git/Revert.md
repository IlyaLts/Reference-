# Revert

The git revert command can be considered an 'undo' type command, however, it is not a traditional undo operation. Instead of removing the commit from the project history, it figures out how to invert the changes introduced by the commit and appends a new commit with the resulting inverse content. This prevents Git from losing history, which is important for the integrity of your revision history and for reliable collaboration.

Reverting should be used when you want to apply the inverse of a commit from your project history. This can be useful, for example, if you’re tracking down a bug and find that it was introduced by a single commit. Instead of manually going in, fixing it, and committing a new snapshot, you can use git revert to automatically do all of this for you.

- Revert the commit with a new commit  
```git revert HEAD``` or ```git revert <commit-hash> -m "revert commit"```

- Revent the commit to the staging index  
```git revert --n HEAD``` or ```git revert --no-commit <commit-hash>```

# Config

- Set your username  
```git config --global user.name "FIRST_NAME LAST_NAME"```

- Set your email address  
```git config --global user.email "MY_NAME@example.com"```

- We can use git-credential-cache to cache our username and password for a time period. Simply enter the following in your CLI (terminal or command prompt):  
```git config --global credential.helper cache```

- You can also set the timeout period (in seconds) as such:  
```git config --global credential.helper 'cache --timeout=3600'```

- Attention: This method saves the credentials in plaintext on your PC's disk. Everyone on your computer can access it, e.g. malicious NPM modules.  
```git config --global credential.helper store```

- Show all Git config properties  
```git config --list```

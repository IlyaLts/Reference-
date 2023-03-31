*(Copy/Paste this to Windows PowerShell)*

Fix WSL2 no internet issue on Windows 10
==================================================
```
wsl --shutdown  
netsh winsock reset
netsh int ip reset all
netsh winhttp reset proxy
ipconfig /flushdns`  
```

Then restart Windows

### Or

```
echo "Restarting WSL Service"
Restart-Service LxssManager
echo "Restarting Host Network Service"
Stop-Service -name "hns"
Start-Service -name "hns"
echo "Restarting Hyper-V adapters"
Get-NetAdapter -IncludeHidden | Where-Object `
    {$_.InterfaceDescription.StartsWith('Hyper-V Virtual Switch Extension Adapter')} `
    | Disable-NetAdapter -Confirm:$False
Get-NetAdapter -IncludeHidden | Where-Object `
    {$_.InterfaceDescription.StartsWith('Hyper-V Virtual Switch Extension Adapter')} `
    | Enable-NetAdapter -Confirm:$False
```
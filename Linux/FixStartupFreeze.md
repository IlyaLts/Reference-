NVIDIA graphics are glitchy with Ubuntu 15.10 and up. Some people don't have problems, while others get exactly what you're getting. Luckily, it's a pretty easy fix.

When the GRUB menu comes up, asking you what you want to do, highlight Try Ubuntu and press E. At the end of the line beginning with linux, enter nouveau.modeset=0. Press F10 to boot into the Live Session.

Once you install Ubuntu, you'll want to take a look here: Graphics issues after/while installing Ubuntu 16.04/16.10 with NVIDIA graphics
This is a very simple project I have been working on for the past 2 days.
# Crisis
A process hacking toolset made for Mach-based systems (primarily macOS)

# Why?
I haven't seen anything similar to this for Mach-based systems. Besides that, the API documentation is either cancer (https://developer.apple.com/documentation/kernel/ kekw) or simply 20 years old.
Just thought this would be fun to make, a lot is coming up in the future :D
* Offset reading/writing
* Pointer scanning (since the stack isn't as reliable)
* Better TUI (ffs)
* Support for other reading/writing modes

And a lot more!

# How can you run this?
You probably can't, since you don't run macOS, but if you do:
I included a test program, so go ahead and try that.

Make sure to run the program using `sudo`, as you *will* get an error. If it asks you to do so, disable SIP.
```c
./compile.sh
sudo ./bin/attacker

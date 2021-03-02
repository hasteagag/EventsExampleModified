# EventsMod
For Corsair keyboards and mice with G and M keys, this modified "Events" Example from recent SDK releases will emit registerable and recognisable keys using the keybd_event method detailed here https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-keybd_event

Other code could be shaved, including the attempt to read the current icue profile, which is dependent on expected rgb values on the Q key.  That was abandonded, but one might suggest using the windows API to request the current state of a key to determine the active profile if a better method is not available (based on some Elgato integrations this might be on the near horizon?).

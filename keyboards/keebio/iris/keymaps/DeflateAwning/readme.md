# DeflateAwning

This keyboard layout was forked from the `keebio/iris -> dvorak` mapping, with inspiration from a few other layouts.

## Notable Changes
* The lshift key is on the left thumb, allowing it to act as capslock for acronyms easily, and making it accessible for hotkeys.
* Modifier keys (Ctrl, Shift, Win, Alt, etc.) are kept mostly constant between layers.
* Pressing LOWER+Tab sends the Alt+Tab hotkey to cycle through Windows.

## To Do Changes

* Being able to shift-select with the arrow keys, and jump by word with the arrow keys is paramount. Plan: setup the vi arrow keys, when SDF are all pressed (which rarely happens in words as OEU).
* Game mode, especially for copy/paste/cut hotkeys, which are very useful on the left hand.
* Setup Plover via Gemini PR protocol.
* Move a Ctrl key to Layer 2 in the same location as on the Base Layer.
* Create PDF to print.

## Building

```
qmk compile -kb keebio/iris/rev6b -km DeflateAwning
```

Tested with Iris Rev 6.1, on QMK keyboard model `rev6b`.

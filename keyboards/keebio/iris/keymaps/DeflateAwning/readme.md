# DeflateAwning

This keyboard layout was forked from the `keebio/iris -> dvorak` mapping, with inspiration from a few other layouts.

## Notable Changes
* The lshift key is on the left thumb, allowing it to act as capslock for acronyms easily, and making it accessible for hotkeys.
* Modifier keys (Ctrl, Shift, Win, Alt, etc.) are kept mostly constant between layers.
* Pressing LOWER+Tab sends the Alt+Tab hotkey to cycle through Windows.
* When SDF (OEU) are all pressed (which rarely happens in words as OEU), the right hand home row works as arrow keys/home/end.
    * Shift-selecting with the arrow keys, and jumping by word with the arrow keys and Ctrl is easy.
* SHIFT+Backpace sends forwards DELETE

## To Do Changes
* Game mode, especially for copy/paste/cut/undo hotkeys, which are very useful on the left hand.
* Setup Plover via Gemini PR protocol.
* Create PDF cheat sheet to print.
* Holding the LOWER key doesn't continue holding Alt for Alt+Tab

## Building

```
qmk compile -kb keebio/iris/rev6b -km DeflateAwning
```

Tested with Iris Rev 6.1, on QMK keyboard model `rev6b`.

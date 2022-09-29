# DeflateAwning

This keyboard layout was forked from the `keebio/iris -> dvorak` mapping, with inspiration from a few other layouts.

## Notable Changes
* I kept hitting the left-thumb key and pressing enter, which is sometimes disasterous on a prompt. The enter and lshift keys are swapped.
* Modifier keys (Ctrl, Shift, Win, Alt, etc.) should be kept mostly constant between layers.

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

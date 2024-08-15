# DeflateAwning

This keyboard layout was forked from the `keebio/iris -> dvorak` mapping, with inspiration from a few other layouts.

## Notable Changes
* Default base layer is Dvorak, but QWERTY mode can be activated to use hotkeys easier (e.g., cut/copy/paste/refresh/bold).
* The lshift key is on the left thumb, allowing it to act as capslock for acronyms easily, and making it accessible for hotkeys.
* Modifier keys (Ctrl, Shift, Win, Alt, etc.) are kept mostly constant between layers.
* Pressing LOWER+Tab sends the Alt+Tab hotkey to cycle through Windows.
    * Pressing LOWER+Tab continues holding Alt down as long as LOWER is down, as you'd expect.
* When SDF (OEU) are all pressed (which rarely happens in words as OEU), the right hand home row works as arrow keys/home/end (similar to in VI). All other keys remain transparent for typing.
    * Shift-selecting with the arrow keys, and jumping by word with the arrow keys and Ctrl is easy.
* SHIFT+Backpace sends forwards DELETE.

## To Do Changes
* Striking the left-thumb shift key very fast should type a space.
* Turn lights on when QWERTY mode is on, and highlight the exit key from QWERTY mode. (https://github.com/lalde/iris_keymap/blob/master/keymap.c)
* Ctrl+Backspace deletes word behind cursor already; make Ctrl+Shift+Backspace delete word ahead of cursor by jumping forward a word then Ctrl+Backspacing in one big macro.

## Building

```bash
qmk compile -kb keebio/iris/rev6b -km DeflateAwning
```

Tested with Iris Rev 6.1, on QMK keyboard model `rev6b`.

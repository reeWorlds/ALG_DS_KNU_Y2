import tkinter as tk

# ---- UI tuning ----
FONT_MAIN  = ("Consolas", 22)
FONT_BTN   = ("Consolas", 16)
FONT_STACK = ("Consolas", 14)

MAX_STACK_VIEW = 20


class Editor:
    def __init__(self, root):
        self.text = []
        self.cursor = 0
        self.undo = []

        # ---- text display ----
        self.entry = tk.Entry(
            root, font=FONT_MAIN, width=32, state="readonly", justify="left"
        )
        self.entry.grid(row=0, column=0, columnspan=6, pady=10)

        # ---- add buttons ----
        for i, ch in enumerate("abcd"):
            tk.Button(
                root, text=ch, width=4, font=FONT_BTN,
                command=lambda c=ch: self.add(c)
            ).grid(row=1, column=i, padx=3)

        # ---- control buttons ----
        tk.Button(
            root, text="←", width=4, font=FONT_BTN,
            command=lambda: self.move(-1)
        ).grid(row=2, column=0, padx=3)

        tk.Button(
            root, text="→", width=4, font=FONT_BTN,
            command=lambda: self.move(+1)
        ).grid(row=2, column=1, padx=3)

        tk.Button(
            root, text="Undo", width=8, font=FONT_BTN,
            command=self.undo_action
        ).grid(row=2, column=2, columnspan=2, padx=3)

        tk.Button(
            root, text="Clear", width=8, font=FONT_BTN,
            command=self.clear_all
        ).grid(row=2, column=4, columnspan=2, padx=3)

        # ---- stack view ----
        self.stack_view = tk.Listbox(
            root, height=12, width=40, font=FONT_STACK
        )
        self.stack_view.grid(row=3, column=0, columnspan=6, pady=10)

        self.refresh()

    # ---- operations ----

    def add(self, ch):
        self.text.insert(self.cursor, ch)
        self.cursor += 1
        self.undo.append(("add", ch))
        self.refresh()

    def move(self, delta):
        new_pos = self.cursor + delta
        if 0 <= new_pos <= len(self.text):
            self.cursor = new_pos
            self.undo.append(("move", delta))
            self.refresh()

    def undo_action(self):
        if not self.undo:
            return

        op, val = self.undo.pop()

        if op == "add":
            self.cursor -= 1
            del self.text[self.cursor]

        elif op == "move":
            self.cursor -= val

        self.refresh()

    def clear_all(self):
        self.text.clear()
        self.cursor = 0
        self.undo.clear()
        self.refresh()

    # ---- UI sync ----

    def refresh(self):
        s = "".join(self.text)
        shown = s[:self.cursor] + "|" + s[self.cursor:]

        self.entry.config(state="normal")
        self.entry.delete(0, tk.END)
        self.entry.insert(0, shown)
        self.entry.config(state="readonly")

        self.stack_view.delete(0, tk.END)
        total = len(self.undo)
        for i, op in enumerate(reversed(self.undo[-MAX_STACK_VIEW:])):
            idx = total - i
            self.stack_view.insert(tk.END, f"{idx:02d}: {op}")


# ---- run ----
root = tk.Tk()
root.title("Minimal Stack-Based Text Editor")
Editor(root)
root.mainloop()

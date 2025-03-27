# OOP

## Structured Programming

### Requests

- Pick up a problem on Judge Girl
- Make it structured

### Result

- Problem: [10428. $n$ in a Grid](https://judgegirl.csie.org/problem/305/10428)
- private
  - 使用者並不需要知道 `grid` 的型態（是array或是unsigned 64-bit integer）
  - 但在C語言中，無法實現此功能，因此還是要在`10428.c`宣告變數，再傳參數
- public
  - `count_row`, `count_col`, `count_dia`, `count_adia`
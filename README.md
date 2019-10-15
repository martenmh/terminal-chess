# Terminal Chess
```
    a  b  c  d  e  f  g  h
  -------------------------
8 |BR|BN|BB|BK|BQ|BB|BN|BR|
  |--|--|--|--|--|--|--|--|
7 |BP|BP|BP|BP|BP|BP|BP|BP|
  |--|--|--|--|--|--|--|--|
6 |  |  |  |  |  |  |  |  |
  |--|--|--|--|--|--|--|--|
5 |  |  |  |  |  |  |  |  |
  |--|--|--|--|--|--|--|--|
4 |  |  |  |  |  |  |  |  |
  |--|--|--|--|--|--|--|--|
3 |  |  |  |  |  |  |  |  |
  |--|--|--|--|--|--|--|--|
2 |WP|WP|WP|WP|WP|WP|WP|WP|
  |--|--|--|--|--|--|--|--|
1 |WR|WN|WB|WK|WQ|WB|WN|WR|
  |--|--|--|--|--|--|--|--|
  
```



## Display possibilities?

* with or without lines horizontal lines
* with or without lines horizontal vertical lines
* with or without piece colors (in terminal eg. |BR| vs |<span
  style="color:black;">**R**</span>|) 
* bold pieces or not
* lines with - or _
* room between piece and lines?

```
         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

Additionally, you can use these:

reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
```
# 專案名稱

## 工業配線故障檢測模擬考試軟體

### 組員
__41243216 李宗燁__  
__41243218 林承志__  
__41243219 林厚丞__

### 專案背景與目的

以前高中的時候練習工業配線丙級，總是覺得練習時間不夠，然後又不可能帶著整個箱子回家，但是在家又很想要練習
而如果在家想要練習的話就只能一直看著課本，沒有實際操作的機會，加上目前沒有人專門替這項考試製作模擬軟體的，那在基於省錢的條件下
在QT實作是最好的選擇，雖然比起SIEMENS或三菱這些工業控制的來講比較難寫，但QT不用額外花錢買軟體，也不需要實際的設備(PLC)
並且也不會像SIEMENS的程式一樣對電腦有很高的要求
那目的就是，製作一個不挑地點、不挑設備、隨時可以運行的模擬控制電路的軟體，加深學生的印象

#### 功能需求

製作工業配線丙級故障檢測題目中，所有元件的圖片與型態切換，還有題目當中的電路邏輯以及故障點的設置，並且可以有效模擬控制電路的功能

#### 組員分工

林厚丞 建立電路元件的類別及大部分框架 還有視窗的建立 亂數以及回饋 等...  
林承志 寫三題電路邏輯 7+8+7個故障點邏輯 實際操作檢查問題 等...  
李宗燁 在過程中解決很鬼畜的BUG 解決了按鈕按下釋放的問題 跟BZ蜂鳴器聲音問題 還有FR閃爍電驛在QT的實現 等...   
鬼畜的BUG就是CODE看起來根本沒問題但執行時很多問題 = = 

基本上我們實作的時候都在一起做 沒有組員耍廢的問題 

#### 心得

這個專題期初在想的時候，原本只打算做一題來演示，不過老師要求3題，所以我們也是從報告完就開始爆肝製作了，前期困難真的很大，
從零開始建構的時候，為了驅動方法吵了很久，一直在想要用while loop不斷檢查邏輯，還是使用事件驅動，因為原本第一版測試的時候，
事件驅動的模型問題蠻多的，要加上很多限制，但實作其實還是比較簡易，所以最後依然選了事件驅動，讀完電路圖後，利用主動式元件按下後，
影響被動式元件的結果來製作，基本上就是按下按鈕然後到達結果。
做到現在終於是完工了，不過在暴力的使用下可能還是會有些許bug，如果要最完善的話可能需要用繪圖軟體把美觀給做好，現在的介面是直接參照PLC的人機介面製作的。
我們對這個專題真的很用心，花了很長的時間，最後看到他真的成功可以用，真的很感動。

#### 專題說明

就是模擬工業配線故障檢測箱，控制電路的功能，詳細看影片我有針對故障做講解，如果還有問題可以參考我的word有一篇我自己打來講解故障點的。

#### DEMO影片

影片是有聲音的 記得開聲音聽 但不要開太大 我們的BZ聲音超級大 會傷害耳朵
https://youtu.be/5mh3zH0cW60

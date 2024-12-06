Qt 期末專題開發計畫

專案名稱

多功能程式作業管理工具

專案背景與目的

隨著程式設計作業需求的增加，學生需要一個便捷的工具來管理、查看、執行及分享程式作業。本專案旨在開發一個基於 Qt 的桌面應用，通過簡單的操作滿足日常的作業管理需求，並增強學習效率。

功能需求

主功能

1. 作業查看與編譯執行

提供基於日期與類型篩選作業的功能。

允許用戶在應用內直接查看作業內容（支援程式碼高亮）。

支援直接編譯並執行程式作業，顯示輸出結果。


次要功能

1. 登入系統

用於管理使用者帳號及相關數據。

支援基本的註冊、登入與登出功能。



2. 作業傳輸功能

通過 TCP 協議傳送作業給指定的使用者。

支援作業的上傳至伺服器，並保存至伺服端的用戶目錄中。



3. 伺服器下載功能

支援從伺服器下載作業到本地端，用於備份或編輯。




使用技術

1. Qt Widgets：用於構建桌面應用的圖形介面。


2. Qt Network 模組：用於實現 TCP 通信功能。


3. Qt Core：提供作業數據的管理與邏輯處理。


4. C++ 編譯器整合：通過 QProcess 模組調用編譯器並執行程式。


5. SQLite：用於管理用戶帳號與作業數據的本地存儲。

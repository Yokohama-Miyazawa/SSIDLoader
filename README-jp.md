[English README](./README.md)
# SSIDLoader  
MicroSDのCSVファイルからSSIDとパスワードを読み込む、Arduino用ライブラリ  
SSIDおよびパスワードは複数設定可能。  

## 使い方  
aps.csvというCSVファイルにSSIDとパスワードを以下のように記述する。
```
SSID1,password_of_ssid1
SSID2,password_of_ssid2
SSID3,password_of_ssid3
```
aps.csvをMicroSDカードのルートディレクトリに配置する。  
プログラムから関数`addAPfromSD()`を呼び出してSSID情報を登録し、  
次に`connectToAP()`関数を呼び出してアクセスポイントに接続する。  

## 関数の説明
### `addAPfromSD` 
引数`fileName`で指定されたCSVファイルを読み込み、記述されたSSIDとパスワードを登録する。  
`fileName`は省略可能で、その場合はルートディレクトリのaps.csvファイルを読み込む。   
#### 書式  
`void addAPfromSD()`  
`void addAPfromSD(const char* fileName="/aps.csv")`  

### `connectToAP()`  
`addAPfromSD`で登録したアクセスポイントに接続する。  
引数`numberOfTrials`を指定すると、その回数接続を繰り返しても接続できない場合は接続を断念する。  
#### 書式  
`bool connectToAP()`  
`bool connectToAP(const uint8_t numberOfTrials)`  

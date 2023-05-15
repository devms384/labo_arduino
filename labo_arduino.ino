char rcvBuf[33];
String rcvStr = "I am Arduino";

void setup() {
  Serial.begin( 9600 );     // シリアル通信を初期化する。通信速度は9600bps
  Serial.println( "Hello Arduino!" );   // 最初に1回だけメッセージを表示する
  pinMode( 13, OUTPUT );

}

void loop() {
  char key;     // 受信データを格納するchar型の変数
  bool hasData = false;
  int index = 0;

  //Serial.println("LoopStart\n");
  // 受信データがあった時だけ、処理を行う
  if ( Serial.available() > 0 ) {       // 受信データがあるか？
    hasData = true;
    //rcvBuf[index] = Serial.read();            // 1文字だけ読み込む
    Serial.readBytesUntil("\0", rcvBuf, 32);
    index=32;
  }
  rcvBuf[index] = "\0";
  if ( hasData == true ){
    rcvStr = rcvBuf;
    rcvStr.trim();
    if(rcvStr.equalsIgnoreCase("on")){
      digitalWrite( 13, HIGH );      // LED ON
    } else if(rcvStr.equalsIgnoreCase("off")){
      digitalWrite( 13, LOW );      // LED OFF
    }
    Serial.println(rcvStr);    
  }

}

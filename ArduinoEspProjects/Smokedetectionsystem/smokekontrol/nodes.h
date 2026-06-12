#define buzzerSound 7

void sirenSound(){
    int i=0;
    for(i=700;i<800;i++){
    tone(buzzerSound,i);
    delay(15);
    }
    for(i=800;i>700;i--){
    tone(buzzerSound,i);
    delay(15);
    }
  }

 

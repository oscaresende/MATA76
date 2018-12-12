import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';

@IonicPage()
@Component({
  selector: 'page-page2',
  templateUrl: 'page2.html'
})
export class Page2 {
  
  nome : String = "";  
  editText : String = "";  
  callback : any;

  constructor(public navCtrl: NavController, public navParams: NavParams) {
    let usuario = navParams.get('nome');  
    this.nome = usuario;
    this.editText = usuario;  
    this.callback = navParams.get('callback');    
  }
  

  confirmar() {

    this.callback(this.editText);
    this.navCtrl.pop();
  };
  
  cancelar() {
    this.callback(this.nome);
    this.navCtrl.pop();
  };
}

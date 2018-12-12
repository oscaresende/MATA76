import { Component } from '@angular/core';
import { IonicPage, NavController } from 'ionic-angular';
import { Page2 } from '../page2/page2';

@IonicPage()
@Component({
  selector: 'page-page1',
  templateUrl: 'page1.html'  
})
export class Page1 {

  usuario : string = "Fulano";
  mensagem : string = "Oi, Fulano!";
  
  constructor(public navCtrl: NavController) {

  }
  alterarFrase(usuario_atual : string)
  {
    if (usuario_atual == "")    
    {
      this.mensagem = "Oi!";
    }
    else
    {
      this.mensagem = "Oi, " + usuario_atual + "!";
    }

    this.usuario = usuario_atual;
  }

  trocar()
  {    
    this.navCtrl.push("Page2", {
      nome: this.usuario,
      'callback' : this.alterarFrase.bind(this)});
  }

}

import { Component } from '@angular/core';
import { IonicPage, NavController } from 'ionic-angular';

@IonicPage()
@Component({
  selector: 'page-page1',
  templateUrl: 'page1.html'
})
export class Page1 {

	mensagem : string = "Alô, Mundo!";
	editNome : string = "";
	
  constructor(public navCtrl: NavController) { }
  
  cumprimentar()
  {
		if (this.editNome =="")
		{
			this.mensagem = "Alô, !";		
		}
		else{
			this.mensagem = "Alô, " + this.editNome + "!"}
		}
		

}

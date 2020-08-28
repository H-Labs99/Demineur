#include "Case.hpp"
using namespace std;

namespace TepeGolo{

    Case::Case(){
        _data->assets.LoadTexture("CaseDos", CASE_DOS_PATH);
        _data->assets.LoadTexture("CaseVide", CASE_VIDE_PATH);
        _data->assets.LoadTexture("Mine1", UN);
        _data->assets.LoadTexture("Mine2", DEUX);
        _data->assets.LoadTexture("Mine3", TROIS);
        _data->assets.LoadTexture("Mine4", QUATRE);
        _data->assets.LoadTexture("CaseMinee", CASE_MINEE_PATH);
        _data->assets.LoadTexture("Fausse", FAUSSE_BOMBE_PATH);
        _data->assets.LoadTexture("CaseMarquee", DRAPEAU);

        _face.setTexture(this->_data->assets.GetTexture("CaseDos"));
        _face.setColor(sf::Color(105,105,105,100));
        //105 105 105
        nombreCaseMineVoisine = 0;
    }

    void Case::afficher(sf::RenderWindow& fenetre){
        fenetre.draw(this->_face);
        _estClicable = true;
    }

    void Case::decouvrir(){
        if(this->_estClicable == true){
            if(this->_estDecouvers == false && this->_estMarque == false){
                if(this->_estMinee == true){
                    _face.setTexture(this->_data->assets.GetTexture("CaseMinee"));
                _estClicable = false;
                }
                else if(this->nombreCaseMineVoisine == 0){
                    _face.setTexture(this->_data->assets.GetTexture("CaseVide"));
                _estClicable = false;
                }
                else if(this->nombreCaseMineVoisine > 0){
                    string nbrMine = "Mine" + to_string(nombreCaseMineVoisine);
                    this->_face.setTexture(this->_data->assets.GetTexture(nbrMine));
                _estClicable = false;
                }
                _face.setColor(sf::Color(255,255,255,255));
                _estDecouvers = true;
            }
        }
    }

    void Case::setPlace(float x, float y){
        _x = x;
        _y = y;
    }

    float Case::getX(){
        return this->_x;
    }

    float Case::getY(){
        return this->_y;
    }

    void Case::placerMine(){
        _estMinee = true;
    }

    void Case::placerCase(float x, float y){
        _face.setPosition(x, y);
        setPlace(x,y);
    }

    void Case::Marquer(){
        if(this->_estMarque == true){
            _face.setTexture(this->_data->assets.GetTexture("CaseDos"));
            _estMarque = false;
            _estClicable = true;
        }
        else{
            _face.setTexture(this->_data->assets.GetTexture("CaseMarquee"));
            _estMarque = true;
            _estClicable = false;
        }
    }

    void Case::ajoutVoisin(){
        this->nombreCaseMineVoisine +=1;
    }

    void Case::FausseBombe(){
        _face.setTexture(this->_data->assets.GetTexture("Fausse"));
    }

}

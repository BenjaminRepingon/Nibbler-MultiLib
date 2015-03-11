#include "Labyrinthe.hpp"

#warning "TODO: copilian form for Labyrinthe"
Labyrinthe::Labyrinthe( float width, float height, int nbr ) :
	_width( width ), _height( height ), _nbr( nbr )
{
	return ;
}

Labyrinthe::~Labyrinthe( void )
{
	return ;
}

void	Labyrinthe::init( void )
{
	for ( int i = 0; i < this->_nbr; i++ )
	{
		for ( int j = 0; j < this->_nbr; j++ )
		{
			#warning "TODO: set Labyrinthe for LabyrintheElement correctly !"
			addComponent( new Wall( ((this->_width / this->_nbr) * i), ((this->_height / this->_nbr) * j), ((this->_width / this->_nbr) * i + 1), ((this->_height / this->_nbr) * j + 1) ) );			
		}
	}
}
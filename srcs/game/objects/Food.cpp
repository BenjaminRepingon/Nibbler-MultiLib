#include "Food.hpp"

#warning "TODO: copilian form for Food"
Food::Food( int nbr ) :
	_nbr( nbr )
{
	return ;
}

Food::~Food( void )
{
	return ;
}

int			Food::update( ILib const * lib, double delta )
{
	for ( size_t i = this->_components.size() - 1; i > 0; i-- )
		this->_components[i]->update( lib, delta );
	// printf("%d\n", this->_dir.get());
	this->_components[0]->setPos(this->_components[0]->getPos());
	return ( true );
}

void		Food::init( void )
{
	for ( size_t i = 0; i < this->_nbr; i++ )
	{
		#warning "TODO: set limit for FoodElement correctly !"
		addComponent( new FoodElement( Vec2i( rand() % 10 , rand() % 10 ) ) );
	}
}
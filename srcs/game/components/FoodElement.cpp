
#include "FoodElement.hpp"

#warning "TODO: copilian form for FoodElement"
FoodElement::FoodElement( Vec2i const & pos )
{
	setPos( pos );
	return ;
}

FoodElement::~FoodElement( void )
{
	return ;
}

int			FoodElement::update( ILib const * lib, double delta )
{

	(void)lib;
	(void)delta;
	return ( true );
}

int			FoodElement::render( ILib const * lib ) const
{
	lib->drawSquare( this->_pos.getX(), this->_pos.getY(), 1, 0x00FFFF );
	return ( true );
}


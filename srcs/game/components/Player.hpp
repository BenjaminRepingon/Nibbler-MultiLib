#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "../../core/AComponent.hpp"
# include "../../utils/vec.hpp"

class Player : public AComponent
{
public:

	Player( Vec2i const & pos);
	~Player( void );
	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;
private:
	int		_score;
};

#endif
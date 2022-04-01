// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

static int turn = 0;

/*----------------------------------------------------------------------------*/
/*                          PRIVATE FUNCTIONS HEADERS                         */
/*----------------------------------------------------------------------------*/

bool equal_directions (direction_t d1, direction_t d2);

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  // TODO: unused parameters, remove these lines later
  UNUSED(attacker_position);
  UNUSED(defender_spy);

  // TODO: Implement Attacker logic here
  static direction_t best_direction;
  static position_t previous_position;
  
  if (turn == 0){
    best_direction = (direction_t) DIR_DOWN_RIGHT;
    previous_position = (position_t) INVALID_POSITION;
  }

  if (equal_positions (previous_position, attacker_position)){
    if (equal_directions (best_direction, (direction_t) DIR_DOWN_RIGHT) ||
        equal_directions (best_direction, (direction_t) DIR_RIGHT)) {
          if (equal_directions (best_direction, (direction_t) DIR_DOWN_RIGHT))
            best_direction = (direction_t) DIR_RIGHT;
          else
            best_direction = (direction_t) DIR_UP;
    }

    else 
      best_direction = (direction_t) DIR_DOWN_RIGHT;
  }
    
      
  turn++;
  previous_position = attacker_position;
  return best_direction;
}


/*----------------------------------------------------------------------------*/
/*                             PRIVATE FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

bool equal_directions (direction_t d1, direction_t d2){
  return d1.i == d2.i && d1.j == d2.j;
}

/*----------------------------------------------------------------------------*/

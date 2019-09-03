#include "..\Class Header\Player.h"
#include "..\Class Header\Card.h"
#include "..\Class Header\Hand.h"
#include "..\Class Header\Shoe.h"
#include "..\Constants\global.h"
#include <iostream>


/**
*   Two issues need to be resolved.
*   1. How to deal with hands over 17?
*   2. How to deal with hands such as A,2,3 = A,5 = 16. Should I use 'action_map' or 'ace_map' ?
**/
std::map< std::pair< int, int >, int > action_map =
{
    /** SEVENTEEN **/
    { std::make_pair(SEVENTEEN, CardValues::TWO),       Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::THREE),     Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::FOUR),      Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::FIVE),      Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::SIX),       Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::SEVEN),     Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::EIGHT),     Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::NINE),      Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::TEN),       Action::Stand },
    { std::make_pair(SEVENTEEN, CardValues::ACE),       Action::Stand },
    /** SIXTEEN **/
    { std::make_pair(SIXTEEN, CardValues::TWO),       Action::Stand },
    { std::make_pair(SIXTEEN, CardValues::THREE),     Action::Stand },
    { std::make_pair(SIXTEEN, CardValues::FOUR),      Action::Stand },
    { std::make_pair(SIXTEEN, CardValues::FIVE),      Action::Stand },
    { std::make_pair(SIXTEEN, CardValues::SIX),       Action::Stand },
    { std::make_pair(SIXTEEN, CardValues::SEVEN),     Action::Hit   },
    { std::make_pair(SIXTEEN, CardValues::EIGHT),     Action::Hit   },
    { std::make_pair(SIXTEEN, CardValues::NINE),      Action::Hit   },
    { std::make_pair(SIXTEEN, CardValues::TEN),       Action::Hit   },
    { std::make_pair(SIXTEEN, CardValues::ACE),       Action::Hit   },
    /** FIFTEEN **/
    { std::make_pair(FIFTEEN, CardValues::TWO),       Action::Stand },
    { std::make_pair(FIFTEEN, CardValues::THREE),     Action::Stand },
    { std::make_pair(FIFTEEN, CardValues::FOUR),      Action::Stand },
    { std::make_pair(FIFTEEN, CardValues::FIVE),      Action::Stand },
    { std::make_pair(FIFTEEN, CardValues::SIX),       Action::Stand },
    { std::make_pair(FIFTEEN, CardValues::SEVEN),     Action::Hit   },
    { std::make_pair(FIFTEEN, CardValues::EIGHT),     Action::Hit   },
    { std::make_pair(FIFTEEN, CardValues::NINE),      Action::Hit   },
    { std::make_pair(FIFTEEN, CardValues::TEN),       Action::Hit   },
    { std::make_pair(FIFTEEN, CardValues::ACE),       Action::Hit   },
    /** FOURTEEN **/
    { std::make_pair(FOURTEEN, CardValues::TWO),       Action::Stand },
    { std::make_pair(FOURTEEN, CardValues::THREE),     Action::Stand },
    { std::make_pair(FOURTEEN, CardValues::FOUR),      Action::Stand },
    { std::make_pair(FOURTEEN, CardValues::FIVE),      Action::Stand },
    { std::make_pair(FOURTEEN, CardValues::SIX),       Action::Stand },
    { std::make_pair(FOURTEEN, CardValues::SEVEN),     Action::Hit   },
    { std::make_pair(FOURTEEN, CardValues::EIGHT),     Action::Hit   },
    { std::make_pair(FOURTEEN, CardValues::NINE),      Action::Hit   },
    { std::make_pair(FOURTEEN, CardValues::TEN),       Action::Hit   },
    { std::make_pair(FOURTEEN, CardValues::ACE),       Action::Hit   },
    /** THIRTEEN **/
    { std::make_pair(THIRTEEN, CardValues::TWO),       Action::Stand },
    { std::make_pair(THIRTEEN, CardValues::THREE),     Action::Stand },
    { std::make_pair(THIRTEEN, CardValues::FOUR),      Action::Stand },
    { std::make_pair(THIRTEEN, CardValues::FIVE),      Action::Stand },
    { std::make_pair(THIRTEEN, CardValues::SIX),       Action::Stand },
    { std::make_pair(THIRTEEN, CardValues::SEVEN),     Action::Hit   },
    { std::make_pair(THIRTEEN, CardValues::EIGHT),     Action::Hit   },
    { std::make_pair(THIRTEEN, CardValues::NINE),      Action::Hit   },
    { std::make_pair(THIRTEEN, CardValues::TEN),       Action::Hit   },
    { std::make_pair(THIRTEEN, CardValues::ACE),       Action::Hit   },
    /** TWELVE **/
    { std::make_pair(TWELVE, CardValues::TWO),       Action::Hit   },
    { std::make_pair(TWELVE, CardValues::THREE),     Action::Hit   },
    { std::make_pair(TWELVE, CardValues::FOUR),      Action::Stand },
    { std::make_pair(TWELVE, CardValues::FIVE),      Action::Stand },
    { std::make_pair(TWELVE, CardValues::SIX),       Action::Stand },
    { std::make_pair(TWELVE, CardValues::SEVEN),     Action::Hit   },
    { std::make_pair(TWELVE, CardValues::EIGHT),     Action::Hit   },
    { std::make_pair(TWELVE, CardValues::NINE),      Action::Hit   },
    { std::make_pair(TWELVE, CardValues::TEN),       Action::Hit   },
    { std::make_pair(TWELVE, CardValues::ACE),       Action::Hit   },
    /** ELEVEN **/
    { std::make_pair(ELEVEN, CardValues::TWO),       Action::Double },
    { std::make_pair(ELEVEN, CardValues::THREE),     Action::Double },
    { std::make_pair(ELEVEN, CardValues::FOUR),      Action::Double },
    { std::make_pair(ELEVEN, CardValues::FIVE),      Action::Double },
    { std::make_pair(ELEVEN, CardValues::SIX),       Action::Double },
    { std::make_pair(ELEVEN, CardValues::SEVEN),     Action::Double },
    { std::make_pair(ELEVEN, CardValues::EIGHT),     Action::Double },
    { std::make_pair(ELEVEN, CardValues::NINE),      Action::Double },
    { std::make_pair(ELEVEN, CardValues::TEN),       Action::Double },
    { std::make_pair(ELEVEN, CardValues::ACE),       Action::Double },
    /** TEN **/
    { std::make_pair(CardValues::TEN, CardValues::TWO),       Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::THREE),     Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::FOUR),      Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::FIVE),      Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::SIX),       Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::SEVEN),     Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::EIGHT),     Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::NINE),      Action::Double },
    { std::make_pair(CardValues::TEN, CardValues::TEN),       Action::Hit    },
    { std::make_pair(CardValues::TEN, CardValues::ACE),       Action::Hit    },
    /** NINE **/
    { std::make_pair(CardValues::NINE, CardValues::TWO),       Action::Double },
    { std::make_pair(CardValues::NINE, CardValues::THREE),     Action::Double },
    { std::make_pair(CardValues::NINE, CardValues::FOUR),      Action::Double },
    { std::make_pair(CardValues::NINE, CardValues::FIVE),      Action::Double },
    { std::make_pair(CardValues::NINE, CardValues::SIX),       Action::Double },
    { std::make_pair(CardValues::NINE, CardValues::SEVEN),     Action::Hit    },
    { std::make_pair(CardValues::NINE, CardValues::EIGHT),     Action::Hit    },
    { std::make_pair(CardValues::NINE, CardValues::NINE),      Action::Hit    },
    { std::make_pair(CardValues::NINE, CardValues::TEN),       Action::Hit    },
    { std::make_pair(CardValues::NINE, CardValues::ACE),       Action::Hit    },
    /** EIGHT **/
    { std::make_pair(CardValues::EIGHT, CardValues::TWO),       Action::Hit    },
    { std::make_pair(CardValues::EIGHT, CardValues::THREE),     Action::Hit    },
    { std::make_pair(CardValues::EIGHT, CardValues::FOUR),      Action::Hit    },
    { std::make_pair(CardValues::EIGHT, CardValues::FIVE),      Action::Double },
    { std::make_pair(CardValues::EIGHT, CardValues::SIX),       Action::Double },
    { std::make_pair(CardValues::EIGHT, CardValues::SEVEN),     Action::Hit    },
    { std::make_pair(CardValues::EIGHT, CardValues::EIGHT),     Action::Hit    },
    { std::make_pair(CardValues::EIGHT, CardValues::NINE),      Action::Hit    },
    { std::make_pair(CardValues::EIGHT, CardValues::TEN),       Action::Hit    },
    { std::make_pair(CardValues::EIGHT, CardValues::ACE),       Action::Hit    },
    /** SEVEN **/
    { std::make_pair(CardValues::SEVEN, CardValues::TWO),       Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::THREE),     Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::FOUR),      Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::FIVE),      Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::SIX),       Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::SEVEN),     Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::EIGHT),     Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::NINE),      Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::TEN),       Action::Hit },
    { std::make_pair(CardValues::SEVEN, CardValues::ACE),       Action::Hit },
    /** SIX **/
    { std::make_pair(CardValues::SIX, CardValues::TWO),       Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::THREE),     Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::FOUR),      Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::FIVE),      Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::SIX),       Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::SEVEN),     Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::EIGHT),     Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::NINE),      Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::TEN),       Action::Hit },
    { std::make_pair(CardValues::SIX, CardValues::ACE),       Action::Hit },
    /** FIVE **/
    { std::make_pair(CardValues::FIVE, CardValues::TWO),       Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::THREE),     Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::FOUR),      Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::FIVE),      Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::SIX),       Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::SEVEN),     Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::EIGHT),     Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::NINE),      Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::TEN),       Action::Hit },
    { std::make_pair(CardValues::FIVE, CardValues::ACE),       Action::Hit },
};

/**
*   Includes Ace-Ten combination
**/
std::map< std::pair< int, int >, int> action_ace_map =
{
    /** BLACKJACK **/
    { std::make_pair(CardValues::TEN, CardValues::TWO),     Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::THREE),   Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::FOUR),    Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::FIVE),    Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::SIX),     Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::SEVEN),   Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::EIGHT),   Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::NINE),    Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::TEN),     Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::ACE),     Action::Stand },
    /** NINE **/
    { std::make_pair(CardValues::NINE, CardValues::TWO),     Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::THREE),   Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::FOUR),    Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::FIVE),    Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::SIX),     Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::SEVEN),   Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::EIGHT),   Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::NINE),    Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::TEN),     Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::ACE),     Action::Stand },
    /** EIGHT **/
    { std::make_pair(CardValues::EIGHT, CardValues::TWO),     Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::THREE),   Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::FOUR),    Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::FIVE),    Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::SIX),     Action::Double },
    { std::make_pair(CardValues::EIGHT, CardValues::SEVEN),   Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::EIGHT),   Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::NINE),    Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::TEN),     Action::Stand  },
    { std::make_pair(CardValues::EIGHT, CardValues::ACE),     Action::Stand  },
    /** SEVEN **/
    { std::make_pair(CardValues::SEVEN, CardValues::TWO),     Action::Stand   },
    { std::make_pair(CardValues::SEVEN, CardValues::THREE),   Action::Double  },
    { std::make_pair(CardValues::SEVEN, CardValues::FOUR),    Action::Double  },
    { std::make_pair(CardValues::SEVEN, CardValues::FIVE),    Action::Double  },
    { std::make_pair(CardValues::SEVEN, CardValues::SIX),     Action::Double  },
    { std::make_pair(CardValues::SEVEN, CardValues::SEVEN),   Action::Stand   },
    { std::make_pair(CardValues::SEVEN, CardValues::EIGHT),   Action::Stand   },
    { std::make_pair(CardValues::SEVEN, CardValues::NINE),    Action::Hit     },
    { std::make_pair(CardValues::SEVEN, CardValues::TEN),     Action::Hit     },
    { std::make_pair(CardValues::SEVEN, CardValues::ACE),     Action::Stand   },
    /** SIX **/
    { std::make_pair(CardValues::SIX, CardValues::TWO),     Action::Double  },
    { std::make_pair(CardValues::SIX, CardValues::THREE),   Action::Double  },
    { std::make_pair(CardValues::SIX, CardValues::FOUR),    Action::Double  },
    { std::make_pair(CardValues::SIX, CardValues::FIVE),    Action::Double  },
    { std::make_pair(CardValues::SIX, CardValues::SIX),     Action::Double  },
    { std::make_pair(CardValues::SIX, CardValues::SEVEN),   Action::Hit     },
    { std::make_pair(CardValues::SIX, CardValues::EIGHT),   Action::Hit     },
    { std::make_pair(CardValues::SIX, CardValues::NINE),    Action::Hit     },
    { std::make_pair(CardValues::SIX, CardValues::TEN),     Action::Hit     },
    { std::make_pair(CardValues::SIX, CardValues::ACE),     Action::Hit     },
    /** FIVE **/
    { std::make_pair(CardValues::FIVE, CardValues::TWO),     Action::Hit    },
    { std::make_pair(CardValues::FIVE, CardValues::THREE),   Action::Hit    },
    { std::make_pair(CardValues::FIVE, CardValues::FOUR),    Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::FIVE),    Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::SIX),     Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::SEVEN),   Action::Hit    },
    { std::make_pair(CardValues::FIVE, CardValues::EIGHT),   Action::Hit    },
    { std::make_pair(CardValues::FIVE, CardValues::NINE),    Action::Hit    },
    { std::make_pair(CardValues::FIVE, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::FIVE, CardValues::ACE),     Action::Hit    },
    /** FOUR **/
    { std::make_pair(CardValues::FOUR, CardValues::TWO),     Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::THREE),   Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::FOUR),    Action::Double },
    { std::make_pair(CardValues::FOUR, CardValues::FIVE),    Action::Double },
    { std::make_pair(CardValues::FOUR, CardValues::SIX),     Action::Double },
    { std::make_pair(CardValues::FOUR, CardValues::SEVEN),   Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::EIGHT),   Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::NINE),    Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::ACE),     Action::Hit    },
    /** THREE **/
    { std::make_pair(CardValues::THREE, CardValues::TWO),     Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::THREE),   Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::FOUR),    Action::Double },
    { std::make_pair(CardValues::THREE, CardValues::FIVE),    Action::Double },
    { std::make_pair(CardValues::THREE, CardValues::SIX),     Action::Double },
    { std::make_pair(CardValues::THREE, CardValues::SEVEN),   Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::EIGHT),   Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::NINE),    Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::ACE),     Action::Hit    },
    /** TWO **/
    { std::make_pair(CardValues::TWO, CardValues::TWO),     Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::THREE),   Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::FOUR),    Action::Double },
    { std::make_pair(CardValues::TWO, CardValues::FIVE),    Action::Double },
    { std::make_pair(CardValues::TWO, CardValues::SIX),     Action::Double },
    { std::make_pair(CardValues::TWO, CardValues::SEVEN),   Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::EIGHT),   Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::NINE),    Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::ACE),     Action::Hit    },
};

/**
*   From left to right: player's card, dealer's card, & the action.
*   Assume that the player's hand is a pair
**/
std::map< std::pair< int , int >, int > action_pair_map =
{
    /** ACE **/
    { std::make_pair(CardValues::ACE, CardValues::TWO),     Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::THREE),   Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::FOUR),    Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::FIVE),    Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::SIX),     Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::SEVEN),   Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::EIGHT),   Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::NINE),    Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::TEN),     Action::Split },
    { std::make_pair(CardValues::ACE, CardValues::ACE),     Action::Split },
    /** TEN **/
    { std::make_pair(CardValues::TEN, CardValues::TWO),     Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::THREE),   Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::FOUR),    Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::FIVE),    Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::SIX),     Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::SEVEN),   Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::EIGHT),   Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::NINE),    Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::TEN),     Action::Stand },
    { std::make_pair(CardValues::TEN, CardValues::ACE),     Action::Stand },
    /** NINE **/
    { std::make_pair(CardValues::NINE, CardValues::TWO),     Action::Split },
    { std::make_pair(CardValues::NINE, CardValues::THREE),   Action::Split },
    { std::make_pair(CardValues::NINE, CardValues::FOUR),    Action::Split },
    { std::make_pair(CardValues::NINE, CardValues::FIVE),    Action::Split },
    { std::make_pair(CardValues::NINE, CardValues::SIX),     Action::Split },
    { std::make_pair(CardValues::NINE, CardValues::SEVEN),   Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::EIGHT),   Action::Split },
    { std::make_pair(CardValues::NINE, CardValues::NINE),    Action::Split },
    { std::make_pair(CardValues::NINE, CardValues::TEN),     Action::Stand },
    { std::make_pair(CardValues::NINE, CardValues::ACE),     Action::Stand },
    /** EIGHT **/
    { std::make_pair(CardValues::EIGHT, CardValues::TWO),     Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::THREE),   Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::FOUR),    Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::FIVE),    Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::SIX),     Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::SEVEN),   Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::EIGHT),   Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::NINE),    Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::TEN),     Action::Split },
    { std::make_pair(CardValues::EIGHT, CardValues::ACE),     Action::Split },
    /** SEVEN **/
    { std::make_pair(CardValues::SEVEN, CardValues::TWO),     Action::Split },
    { std::make_pair(CardValues::SEVEN, CardValues::THREE),   Action::Split },
    { std::make_pair(CardValues::SEVEN, CardValues::FOUR),    Action::Split },
    { std::make_pair(CardValues::SEVEN, CardValues::FIVE),    Action::Split },
    { std::make_pair(CardValues::SEVEN, CardValues::SIX),     Action::Split },
    { std::make_pair(CardValues::SEVEN, CardValues::SEVEN),   Action::Split },
    { std::make_pair(CardValues::SEVEN, CardValues::EIGHT),   Action::Hit   },
    { std::make_pair(CardValues::SEVEN, CardValues::NINE),    Action::Hit   },
    { std::make_pair(CardValues::SEVEN, CardValues::TEN),     Action::Stand },
    { std::make_pair(CardValues::SEVEN, CardValues::ACE),     Action::Hit   },
    /** SIX **/
    { std::make_pair(CardValues::SIX, CardValues::TWO),     Action::Split },
    { std::make_pair(CardValues::SIX, CardValues::THREE),   Action::Split },
    { std::make_pair(CardValues::SIX, CardValues::FOUR),    Action::Split },
    { std::make_pair(CardValues::SIX, CardValues::FIVE),    Action::Split },
    { std::make_pair(CardValues::SIX, CardValues::SIX),     Action::Split },
    { std::make_pair(CardValues::SIX, CardValues::SEVEN),   Action::Hit   },
    { std::make_pair(CardValues::SIX, CardValues::EIGHT),   Action::Hit   },
    { std::make_pair(CardValues::SIX, CardValues::NINE),    Action::Hit   },
    { std::make_pair(CardValues::SIX, CardValues::TEN),     Action::Hit   },
    { std::make_pair(CardValues::SIX, CardValues::ACE),     Action::Hit   },
    /** FIVE **/
    { std::make_pair(CardValues::FIVE, CardValues::TWO),     Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::THREE),   Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::FOUR),    Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::FIVE),    Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::SIX),     Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::SEVEN),   Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::EIGHT),   Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::NINE),    Action::Double },
    { std::make_pair(CardValues::FIVE, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::FIVE, CardValues::ACE),     Action::Hit    },
    /** FOUR **/
    { std::make_pair(CardValues::FOUR, CardValues::TWO),     Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::THREE),   Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::FOUR),    Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::FIVE),    Action::Double },
    { std::make_pair(CardValues::FOUR, CardValues::SIX),     Action::Double },
    { std::make_pair(CardValues::FOUR, CardValues::SEVEN),   Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::EIGHT),   Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::NINE),    Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::FOUR, CardValues::ACE),     Action::Hit    },
    /** THREE **/
    { std::make_pair(CardValues::THREE, CardValues::TWO),     Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::THREE),   Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::FOUR),    Action::Split  },
    { std::make_pair(CardValues::THREE, CardValues::FIVE),    Action::Split  },
    { std::make_pair(CardValues::THREE, CardValues::SIX),     Action::Split  },
    { std::make_pair(CardValues::THREE, CardValues::SEVEN),   Action::Split  },
    { std::make_pair(CardValues::THREE, CardValues::EIGHT),   Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::NINE),    Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::THREE, CardValues::ACE),     Action::Hit    },
    /** TWO **/
    { std::make_pair(CardValues::TWO, CardValues::TWO),     Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::THREE),   Action::Split  },
    { std::make_pair(CardValues::TWO, CardValues::FOUR),    Action::Split  },
    { std::make_pair(CardValues::TWO, CardValues::FIVE),    Action::Split  },
    { std::make_pair(CardValues::TWO, CardValues::SIX),     Action::Split  },
    { std::make_pair(CardValues::TWO, CardValues::SEVEN),   Action::Split  },
    { std::make_pair(CardValues::TWO, CardValues::EIGHT),   Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::NINE),    Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::TEN),     Action::Hit    },
    { std::make_pair(CardValues::TWO, CardValues::ACE),     Action::Hit    },
};

Player::Player()
{
    name = "Player";
    hand.push_back(new Hand);
    chips = PLAYER_STARTING_CHIPS;
}

Player::~Player()
{
    Delete_Hand();
}

void Player::Delete_Hand()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        (*it)->Delete_Hand();
    }
    hand.clear();
}

void Player::Display_Hand() const
{
    int hand_counter = 1;

    std::cout << "Player's hand: " << '\n';

    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        std::cout << "Hand " << hand_counter++ << ": " << '\n';
        (*it)->Display_Hand();
    }
}

void Player::Add_Hand()
{
    hand.push_back(new Hand);
}

/**
*   Assume player initially has one hand with 2 cards.
*   Method first makes sure to split hands.
**/
int Player::Check_For_Split(const int dealer_card, Shoe * shoe)
{
    int action = 0;

    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        if ((*it)->Is_Pair())
        {
            action = action_pair_map[std::make_pair((*it)->First_Card(), dealer_card)];
        }
        else if (hand[0]->Has_Ace())
        {
            ((*it)->First_Card() == CardValues::ACE) ? action = action_ace_map[std::make_pair((*it)->Second_Card(), dealer_card)] :
                                                    action = action_ace_map[std::make_pair((*it)->First_Card(), dealer_card)] ;
        }
        else
        {
            if ((*it)->Hand_Value() > SEVENTEEN)
            {
                action = Action::Stand;
            }
            else
            {
                action = action_map[std::make_pair((*it)->Hand_Value(), dealer_card)];
            }
        }
        switch (action)
        {
            case Action::Split :
            {
                Hand * new_hand = new Hand;
                new_hand->Set_Wager((*it)->Get_Wager());
                new_hand->Add_Card((*it)->Split_Hand());
                new_hand->Add_Card(shoe->pop());
                hand.push_back(new_hand);
                (*it)->Add_Card(shoe->pop());
                /** Reset the iterator to check if the hand needs to be split again. **/
                it = hand.begin();
                break;
            }
            case Action::Hit :
            {
                (*it)->Add_Card(shoe->pop());
                /** Repeat the same hand **/
                --it;
                break;
            }
            case Action::Stand :
            {
                break;
            }
            case Action::Double :
            {
                /** If hand[i] has more than two cards then 'double' works as a 'hit'. Don't double the bet. **/
                if ((*it)->Cards_In_Hand() == 2)
                {
                    (*it)->Double_Wager();
                    (*it)->Add_Card(shoe->pop());
                }
                else
                {
                    (*it)->Add_Card(shoe->pop());
                    /** Repeat the same hand **/
                    --it;
                }
                break;
            }
            default :
                /** Should not get to this point **/
                break;
        }
    }

    return action;
}

void Player::Wager(int wager)
{
    chips -= wager;
    hand[0]->Set_Wager(wager);
}

void Player::Add_Chips(int c)
{
    chips += c;
}

void Player::Subtract_Chips(int c)
{
    chips -= c;
}

void Player::Receive_Card(const Card * new_card)
{
    hand[0]->Add_Card(new_card);
}




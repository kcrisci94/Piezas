/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


/*Tests dropPiece()*/
TEST(PiezasTest, place_1_piece)
{
  Piezas obj;
  ASSERT_EQ(X, obj.dropPiece(0));
}

/*Tests dropPiece()*/
TEST(PiezasTest, place_2_pieces)
{
  Piezas obj;
  obj.dropPiece(0);
  ASSERT_EQ(O, obj.dropPiece(0));
}

/*Tests dropPiece()*/
TEST(PiezasTest, place_in_all_cols)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(1);
  ASSERT_EQ(X, obj.dropPiece(2));
}

/*Tests dropPiece()*/
TEST(PiezasTest, place_4_pieces_1_row)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(0);
  ASSERT_EQ(Invalid, obj.dropPiece(0));
}

/*Tests dropPiece()*/
TEST(PiezasTest, place_invalid_col_neg)
{
  Piezas obj;
  ASSERT_EQ(Invalid, obj.dropPiece(-1));
}

/*Tests dropPiece()*/
TEST(PiezasTest, place_invalid_col_pos)
{
  Piezas obj;
  ASSERT_EQ(Invalid, obj.dropPiece(4));
}

/*Tests pieceAt()*/
TEST(PiezasTest, get_X_piece)
{
  Piezas obj;
  obj.dropPiece(0);
  ASSERT_EQ(X, obj.pieceAt(0, 0));
}

/*Tests pieceAt()*/
TEST(PiezasTest, get_O_piece)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  ASSERT_EQ(O, obj.pieceAt(1, 0));
}

/*Tests pieceAt()*/
TEST(PiezasTest, get_Blank_piece)
{
  Piezas obj;
  ASSERT_EQ(Blank, obj.pieceAt(1, 0));
}

/*Tests pieceAt()*/
TEST(PiezasTest, get_invalid_row_neg)
{
  Piezas obj;
  ASSERT_EQ(Invalid, obj.pieceAt(-1, 0));
}

/*Tests pieceAt()*/
TEST(PiezasTest, get_invalid_row_pos)
{
  Piezas obj;
  ASSERT_EQ(Invalid, obj.pieceAt(3, 0));
}

/*Tests pieceAt()*/
TEST(PiezasTest, get_invalid_col_neg)
{
  Piezas obj;
  ASSERT_EQ(Invalid, obj.pieceAt(1, -1));
}

/*Tests pieceAt()*/
TEST(PiezasTest, get_invalid_col_pos)
{
  Piezas obj;
  ASSERT_EQ(Invalid, obj.pieceAt(2, 4));
}

/*Tests reset()*/
TEST(PiezasTest, reset_board)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(2);
  ASSERT_EQ(X, obj.pieceAt(0, 0));
  ASSERT_EQ(O, obj.pieceAt(1, 0));
  ASSERT_EQ(X, obj.pieceAt(0, 1));
  ASSERT_EQ(O, obj.pieceAt(0, 2));
  ASSERT_EQ(X, obj.pieceAt(1, 2));
  obj.reset();
  ASSERT_EQ(Blank, obj.pieceAt(0, 0));
  ASSERT_EQ(Blank, obj.pieceAt(1, 0));
  ASSERT_EQ(Blank, obj.pieceAt(0, 1));
  ASSERT_EQ(Blank, obj.pieceAt(0, 2));
  ASSERT_EQ(Blank, obj.pieceAt(1, 2));


}

/*Tests gameState()*/
TEST(PiezasTest, game_not_over)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(2);
  ASSERT_EQ(Invalid, obj.gameState());
}

/*Tests gameState()*/
TEST(PiezasTest, X_wins_col_0)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(2);
  obj.dropPiece(0);
  obj.dropPiece(2);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(3);
  obj.dropPiece(3);
  obj.dropPiece(3);
  ASSERT_EQ(X, obj.gameState());
}

/*Tests gameState()*/
TEST(PiezasTest, X_wins_row_0)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(0);
  obj.dropPiece(3);
  obj.dropPiece(1);
  obj.dropPiece(3);
  obj.dropPiece(2);
  obj.dropPiece(2);
  obj.dropPiece(3);
  ASSERT_EQ(X, obj.gameState());
}

/*Tests gameState()*/
TEST(PiezasTest, O_wins_row_1)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(0);
  obj.dropPiece(2);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(3);
  obj.dropPiece(3);
  obj.dropPiece(2);
  obj.dropPiece(3);
  ASSERT_EQ(O, obj.gameState());
}

/*Tests gameState()*/
TEST(PiezasTest, O_wins_col_1)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(1);
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(3);
  obj.dropPiece(1);
  obj.dropPiece(3);
  obj.dropPiece(2);
  obj.dropPiece(2);
  obj.dropPiece(3);
  ASSERT_EQ(O, obj.gameState());
}

/*Tests gameState()*/
TEST(PiezasTest, tie_of_1)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(2);
  obj.dropPiece(2);
  obj.dropPiece(3);
  obj.dropPiece(3);
  obj.dropPiece(3);
  ASSERT_EQ(Blank, obj.gameState());
}

/*Tests gameState()*/
TEST(PiezasTest, tie_of_2)
{
  Piezas obj;
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(2);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(3);
  obj.dropPiece(3);
  obj.dropPiece(3);
  ASSERT_EQ(Blank, obj.gameState());
}


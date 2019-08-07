/**
 *  @file
 *  @copyright luckpoint
 */
#include <utility>
#include <vector>
#include <string>
#include <ultrainiolib/ultrainio.hpp>
#include <ultrainiolib/asset.hpp>

using ultrainio::asset;

class luckpoint : public ultrainio::contract {
  public:
    luckpoint(account_name self)
    :ultrainio::contract(self),
      globals(_self, _self),
      games(_self, _self)
    {}

  public:
    void creategame(const account_name _owner);
    void opencard(uint64_t gameid, const uint32_t player);

    // 测试函数
    void sayhi(account_name receiver);
    void printrand(uint64_t gameid);

  private:
    void _checkgame(uint64_t _gameid);
    void _finishgame(uint64_t _gameid);
    uint32_t _getrandnum(uint64_t _gameid);

  private:

    //@abi table global i64 全局引用计数表
    struct global {
      uint64_t id = 0;
      uint64_t nextgameid = 0;

      uint64_t primary_key()const { return id; }

      ULTRAINLIB_SERIALIZE( global, (id)(nextgameid) )
    };

    // 创建一个多索引容器的游戏引用计数，用于为新游戏生成游戏ID
    typedef ultrainio::multi_index< N(global), global> global_index;
    global_index globals;

    //@abi table game i64 游戏表
    struct game {
      uint64_t      id;           // 游戏ID
      uint32_t      winner;       // 胜出者，0还未决出胜负，1玩家1胜出，2玩家2胜出
      uint32_t      player1;      // 玩家1点数
      uint32_t      player2;      // 玩家2点数
      time          createtime;   // 创建时间
      account_name  owner;        // 创建游戏的账户

      uint64_t primary_key()const { return id; }  // 设置数据主键

      ULTRAINLIB_SERIALIZE( game, (id)(winner)(player1)(player2)(createtime)(owner) )
    };

    // 创建一个多索引容器的游戏列表
    typedef ultrainio::multi_index< N(game), game> game_index;
    game_index games;
};

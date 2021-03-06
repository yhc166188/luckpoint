const char* const luckpoint_abi = R"=====(
{
  "types": [{
      "new_type_name": "account_name",
      "type": "name"
   }],
   "____comment": "",
  "structs": [{
      "name": "global",
      "base": "",
      "fields": [{
          "name": "id",
          "type": "uint64"
        },{
          "name": "nextgameid",
          "type": "uint64"
        }
      ]
    },{
      "name": "game",
      "base": "",
      "fields": [{
          "name": "id",
          "type": "uint64"
        },{
          "name": "winner",
          "type": "uint32"
        },{
          "name": "player1",
          "type": "uint32"
        },{
          "name": "player2",
          "type": "uint32"
        },{
          "name": "createtime",
          "type": "uint32"
        },{
          "name": "owner",
          "type": "account_name"
        }
      ]
    },{
      "name": "creategame",
      "base": "",
      "fields": [{
          "name": "owner",
          "type": "account_name"
        }
      ]
    },{
      "name": "opencard",
      "base": "",
      "fields": [{
          "name": "gameid",
          "type": "uint64"
        },{
          "name": "player",
          "type": "uint32"
        }
      ]
    },{
      "name": "sayhi",
      "base": "",
      "fields": [{
          "name": "receiver",
          "type": "account_name"
        }
      ]
    },{
      "name": "printrand",
      "base": "",
      "fields": [{
          "name": "gameid",
          "type": "uint64"
        }
      ]
    }
  ],
  "actions": [{
      "name": "creategame",
      "type": "creategame",
      "ricardian_contract": ""
    },{
      "name": "opencard",
      "type": "opencard",
      "ricardian_contract": ""
    },{
      "name": "sayhi",
      "type": "sayhi",
      "ricardian_contract": ""
    },{
      "name": "printrand",
      "type": "printrand",
      "ricardian_contract": ""
    }
  ],
  "tables": [{
      "name": "global",
      "index_type": "i64",
      "key_names": [
        "id"
      ],
      "key_types": [
        "uint64"
      ],
      "type": "global"
    },{
      "name": "game",
      "type": "game"
      "index_type": "i64",
      "key_names": [
        "id"
      ],
      "key_types": [
        "uint64"
      ],
    }
  ],
  "ricardian_clauses": [],
  "abi_extensions": []
})=====";

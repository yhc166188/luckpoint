const { createU3 } = require('u3.js');
let config = {
    httpEndpoint: "http://172.16.10.9:8899",
    httpEndpointHistory: "http://172.16.10.6:3001",
    chainId: "20c35b993c10b5ea1007014857bb2b8832fb8ae22e9dcfdc61dacf336af4450f",
    broadcast: true,
    sign: true,
    logger: {
      directory: "./logs", // daily rotate file directory
      level: "info", // error->warn->info->verbose->debug->silly
      console: true, // print to console
      file: false // append to file
    },
    symbol: "UGAS",
    //keyProvider:[],
    //expireInSeconds:60
}
let u3 = createU3(config);

u3.getChainInfo((err, info) => {
  if (err) {throw err;}
  console.log(info);
});
let contract_name = 'luckpoint1'
let account_name = 'luckpoint1'
u3.contract(contract_name)

let info1 = u3.getTableRecords({"scope":contract_name, "code":contract_name, "table":"game", "json": true})
console.log(info1);
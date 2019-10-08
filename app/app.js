const Web3 = require('web3');
const mqtt = require('mqtt');
const compiledContract = require('./Lampe21Contract.json');

const client = mqtt.connect('mqtt://10.0.1.48');
const web3js = new Web3(Web3.givenProvider || 'ws://localhost:7545')
const contractAddress = '0x8d109b6D2dB5a638C79DBcA1d5d29Fb3f0ce7719';
const mapping = {
  '0453446A643481': '0x1b268E435019ca4d2a898F76c5156dcF54d00146'
}

function getContract(uid) {
  return new web3js.eth.Contract(compiledContract.abi, contractAddress, {
    from: mapping[uid]
  });
}

client.on('connect', function () {
  client.subscribe('/nfctest123', console.info);
})

client.on('message', async (topic, message) => {
  switch (topic) {
    case '/nfctest123':
      try {
        const uid = message.toString();
        const buyLight = getContract(uid).methods.buyLight;
        await buyLight.send({
          from: mapping[uid],
          value: Math.pow(10, 18)
        });
        client.publish('/lampe21Status', 'TOGGLE', console.error);
      } catch (error) {
        console.error(error);
      }
      break;
    default:
      console.error(`Uknown topic "${topic}"`);
      break;
  }
});
const Lampe21Contract = artifacts.require('Lampe21Contract');

module.exports = function(deployer) {
  deployer.deploy(Lampe21Contract);
};

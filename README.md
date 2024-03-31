# sovellusprojekti



### SQL-koodi car nimisen taulun luomiseen:
CREATE TABLE IF NOT EXISTS `netdb`.`car` (
  `idcar` INT NOT NULL AUTO_INCREMENT,
  `branch` VARCHAR(45) NULL,
  `model` VARCHAR(45) NULL,
  PRIMARY KEY (`idcar`))
ENGINE = InnoDB;
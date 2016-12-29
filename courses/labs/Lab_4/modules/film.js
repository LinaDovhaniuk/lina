var mongoose = require('mongoose');

var Schema = mongoose.Schema;
var Film = new Schema({
  title : {
      type: String,
      unique: true,
      required: true
  },
  year : {
      type: String,
      required: true
  },
  country : {
    type: String,
    required: true
  },
  director : {
    type: String,
    required: true
  },
  raiting : {
      type: Number,
      required: true
  },
  img : {
    type : String
  }
});

var FilmModel = mongoose.model('Film', Film);

module.exports = FilmModel;

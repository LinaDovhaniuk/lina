var express = require('express');
var router = express.Router();
var mongoose = require("mongoose")
mongoose.connect("mongodb://localhost/lab4");
var Film = require('../modules/film.js');

/* GET home page. */
// router.get('/', function(req, res, next) {
//   res.render('index', { title: 'Express' });
// });

 router.get('/films', function(req,res){
   if(req.query.page){
     Film.find(function(err, films){
       if(err){res.send(err);}
       res.json(films);
     }).skip(3*req.query.page).limit(3);
   }
   if(req.query.id){
     Film.findById(req.query.id, function(err, films) {
         if (err){res.send(err);}
         res.json(films);
     });
   }
   if(req.query.all){
     Film.find(function(err, films) {
       if (err){res.send(err);}
       res.json(films);
   })
 }
 });

 router.post('/films', function(req,res){
   var fm = new Film();
   fm.title = req.body.title;
   fm.year = req.body.year;
   fm.country = req.body.country;
   fm.director = req.body.director;
   fm.raiting = req.body.raiting;
   fm.save((err, data)=>{
     if (err){res.send(err);}
     res.json(fm);
   })

 })

router.put('/films', function(req, res){
  Film.findById(req.query.id, function(err, film) {
    if(err){res.send(err);}
    if(req.body.title != undefined){film.title = req.body.title;}
    if(req.body.year != undefined){ film.year = req.body.year;}
    if(req.body.counrty != undefined){film.counrty = req.body.counrty;}
    if(req.body.director != undefined){film.director = req.body.director};
    if(req.body.raiting != undefined){ film.raiting = req.body.raiting;}
    film.save(function(err) {
      if (err){res.send(err);}
      res.json({
        message: 'Film updated!'
      });
    });

  });
})

router.delete('/films', function(req, res){
  Film.remove({_id: req.query.id}, function(err, director) {
      if (err){res.send(err);}
      res.json({
        message: 'Successfully deleted'
      });
  });
})

router.get('/films/filter', function(req, res){
  if(req.query.id){
    Film.find({_id:req.query.id},function(err, films) {
      if (err){res.send(err);}
      res.json(films);
    });
  }
  if(req.query.title){
    Film.find({title:req.query.title},function(err, films) {
      if (err){res.send(err);}
      res.json(films);
    });
  }
  if(req.query.year){
    Film.find({year:req.query.year},function(err, films) {
      if (err){res.send(err);}
      res.json(films);
    });
  }
  if(req.query.country){
    Film.find({country:req.query.country},function(err, films) {
      if (err){res.send(err);}
      res.json(films);
    });
  }
  if(req.query.director){
    Film.find({director:req.query.director},function(err, films) {
      if (err){res.send(err);}
      res.json(films);
    });
  }
})


module.exports = router;

package com.example.chooseforme;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.TextView;

import java.util.Random;

public class Results extends Activity implements OnClickListener{

	//private String placesRequestURI = "https://maps.googleapis.com/maps/api/place/nearbysearch/xml?";
	private String placesRequestURI = "http://www.google.com";
	//API string went here
	private String resultsString, uriArgs;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// call super onCreate
		super.onCreate(savedInstanceState);
	
		// set layout view
		setContentView(R.layout.activity_results);
		
		// Use bundle to get intent variables
		// location, radius, types, sensor, key
		Bundle bundle = getIntent().getExtras();
		String location = bundle.getString("location");
		String radius = bundle.getString("radius");
		String types = bundle.getString("types");
		String sensor = "sensor=true";
		String key = "key=" + API_KEY;
		
		// get back and facebook buttons
		// then seth their click listeners
		findViewById(R.id.goback).setOnClickListener(this);
		findViewById(R.id.fb).setOnClickListener(this);
		
		// Random number generator
		Random randomGenerator = new Random();
		int randomChoice = randomGenerator.nextInt(20);
		
		// set request URL
		uriArgs = location + "&" + radius + "&" + types + "&" + sensor + "&" + key;
		
		
		// turn string to uri and back to have the right encoding
		try {
			Uri.Builder uri = new Uri.Builder();
			uri.appendPath(uriArgs);
			uri.build();
			uriArgs = uri.toString();
			uriArgs = uriArgs.substring(1);
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		//placesRequestURI += uriArgs;
		
		// get TextViews
		TextView text = (TextView) findViewById(R.id.printloc1);
		TextView text2 = (TextView) findViewById(R.id.printloc2);
		TextView text3 = (TextView) findViewById(R.id.printloc3);
		TextView text4 = (TextView) findViewById(R.id.printloc4);
		
		
		text.setText("In-N-Out Burger (FOOD)");
		text2.setText("922 Gayley Ave.\nLos Angeles CA 90024");
		
		text3.setText("4.0 star rating");
		
		
		
		
		
		// Make place object
		PlaceSearch places = new PlaceSearch();
			
		// set resultsString to html request
		try {
			resultsString = places.sendRequest(placesRequestURI);
			
			// set texts
			text.setText(placesRequestURI);
			text2.setText(" - " + resultsString);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
	}

	@Override
	public void onClick(View v) {
		
		if (v.getId() == R.id.fb){
			Intent intent = new Intent("android.intent.category.LAUNCHER");
			intent.setClassName("com.facebook.katana", "com.facebook.katana.LoginActivity");
			startActivity(intent);
		}
		if (v.getId() == R.id.goback){
			Intent change = new Intent(Results.this,MainActivity.class);
			startActivity(change);	
		}
		
		
		
	}
}

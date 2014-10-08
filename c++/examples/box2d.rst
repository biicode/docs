.. _box2d:


Box2D
-----

|box2d_homepage| is an open source C++ engine to simulate rigid bodies in 2D, it is also, AngryBirds motor engine. You can check |wiki_box2d|. 

The main block is |bii_box2d|, which is generated from this |fork_box2d|.

Bounces of a circle falling
----------------------------

In this example you will calculate whenever a circle falls from a certain height and bounces at a defined lower limit in the created world. Then, create a project, one block and copy the bellow main.cpp file:

.. code-block:: bash

   ~$ bii init box2d
   ~$ cd box2d
   ~/box2d$ bii new myuser/box2d_example --hello cpp

Now **replace the main.cpp** file in ``blocks/myuser/box2d_example`` with 
the following code:

.. code-block:: cpp

    #include "erincatto/box2d/Box2D/Box2D.h"
    #include <iostream>

    using namespace std;

    int main(int argc, char** argv)
    {
        B2_NOT_USED(argc);
        B2_NOT_USED(argv);

        //**************************************************//
        //                 Creating a World                        //
        //**************************************************//

        // Define the gravity vector.
        b2Vec2 gravity(0.0f,-10.0f);

        // Construct a world object, which will hold and simulate the rigid bodies.
        b2World world(gravity);


        //**************************************************//
        //                 Creating a Ground Box               //
        //**************************************************//

        // Define the ground body.
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0.0f,-10.0f);

        // Call the body factory which allocates memory for the ground body
        // from a pool and creates the ground box shape (also from a pool).
        // The body is also added to the world.
        b2Body* groundBody = world.CreateBody(&groundBodyDef);

        // Define the ground box shape.
        b2PolygonShape groundBox;

        // The extents are the half-widths of the box.
        groundBox.SetAsBox(50.0f, 10.0f);

        // Add the ground fixture to the ground body.
        groundBody->CreateFixture(&groundBox, 0.0f);

        //**************************************************//
        //            Creating a Circle Shape                   //
        //**************************************************//

        b2BodyDef BodyDef;
        BodyDef.type = b2_dynamicBody;
        BodyDef.position = b2Vec2(0.0f, 4.0f);
        BodyDef.userData = (void *) "Circle";
        b2Body* body = world.CreateBody(&BodyDef);

        b2CircleShape circle;
        circle.m_radius = 1.0f;

        b2FixtureDef fixtureDef;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 2.0f;
        fixtureDef.restitution = 0.5f;

        fixtureDef.shape = &circle;

        body->CreateFixture(&fixtureDef);

        //**************************************************//
        //            Simulating the World (of Box2D)     //
        //**************************************************//

        float32 timeStep = 1.0f / 60.0f;
        int32 velocityIterations = 6;
        int32 positionIterations = 2;

        // This is our little game loop.
        for (int32 i = 0; i < 100; ++i)
        {
            // Instruct the world to perform a single step of simulation.
            // It is generally best to keep the time step and iterations fixed.
            world.Step(timeStep, velocityIterations, positionIterations);

            // Now print the position and angle of the body.
            b2Vec2 position = body->GetPosition();
            float32 angle = body->GetAngle();

            if (position.y - 1.00 <= 0.001)
                cout<< "Ball hits the ground!!" << endl;
            else
                cout<<"X = " << position.x << " Y = " << position.y << endl;
        }
    }


Find your dependency to ``#include "erincatto/box2d/box2d/box2d.h"`` and build the project:

.. code-block:: bash

  ~/box2d$ bii find
  ~/box2d$ bii cpp:build

Execute the binary and this is how the output looks like:

.. code-block:: bash

  ~/box2d$ bin/myuser_box2d_example_main
  X = 0 Y = 3.99722
  X = 0 Y = 3.99167
  X = 0 Y = 3.98333
  X = 0 Y = 3.97222
  X = 0 Y = 3.95833
  X = 0 Y = 3.94167
  X = 0 Y = 3.92222
  Ball hits the ground!!

That's it!

Didn't work? No problem, read or contact us in |biicode_forum_link|

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">Write us!</a>



.. |box2d_homepage| raw:: html

   <a href="http://box2d.org/" target="_blank">Box2D</a>

.. |wiki_box2d| raw:: html

   <a href="http://es.wikipedia.org/wiki/Box2D" target="_blank">wikipedia Box2D explanation</a>

.. |bii_box2d| raw:: html

   <a href="https://www.biicode.com/erincatto/erincatto/box2d/master" target="_blank">here</a>

.. |fork_box2d| raw:: html

   <a href="https://github.com/davidsanfal/box2d" target="_blank">github repo</a>

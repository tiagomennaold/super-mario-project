////////////////////////////////////////////////////////////////////////
// Level.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Level.hpp"
#include "XMLParser.hpp"
#include "MonsterTypes.hpp"

namespace SuperMarioProject
{
	string& Level::getName()
	{
		return _name;
	}

	string& Level::getMusicTitle()
	{
		return _musicTitle;
	}

	Vector2i& Level::getSpawn()
	{
		return _spawn;
	}

	Vector2i& Level::getSize()
	{
		return _size;
	}

	vector<Object*>& Level::getObjects()
	{
		return _objects;
	}

	vector<Checkpoint*>& Level::getCheckpoints()
	{
		return _checkpoints;
	}

	vector<Projectile*>& Level::getProjectiles()
	{
		return _projectiles;
	}

	vector<Monster*>& Level::getMonsters()
	{
		return _monsters;
	}

	vector<Pipe*>& Level::getPipes()
	{
		return _pipes;
	}

	vector<Item*>& Level::getItems()
	{
		return _items;
	}

	vector<Background*>& Level::getBackgrounds()
	{
		return _backgrounds;
	}

	vector<Foreground*>& Level::getForegrounds()
	{
		return _foregrounds;
	}

	vector<Finish*>& Level::getFinishes()
	{
		return _finishes;
	}

	vector<Tileset*>& Level::getTilesets()
	{
		return _tilesets;
	}

	vector<BlockOccurrence*>& Level::getBlocksOccurrences()
	{
		return _blocksOccurrences;
	}

	int Level::getMonsterIndex(Monster* monster)
	{
		int index = 0;
		for(vector<Monster*>::iterator itMonsters = _monsters.begin();
			itMonsters != _monsters.end(); ++itMonsters)
		{
			if((*itMonsters) == monster)
				return index;

			++index;
		}
	}

	void Level::setName(string name)
	{
		_name = name;
	}

	void Level::setSpawnX(int x)
	{
		_spawn.x = x;
	}

	void Level::setSpawnY(int y)
	{
		_spawn.y = y;
	}

	void Level::setWidth(int width)
	{
		_size.x = width;
	}

	void Level::setHeight(int height)
	{
		_size.y = height;
	}

	void Level::setMusicTitle(string title)
	{
		_musicTitle = title;
	}

	void Level::addCheckpoint(Checkpoint* checkpoint)
	{
		_checkpoints.push_back(checkpoint);
	}

	void Level::addBackground(Background* background)
	{
		_backgrounds.push_back(background);
	}

	void Level::addForeground(Foreground* foreground)
	{
		_foregrounds.push_back(foreground);
	}

	void Level::addObject(Object* object)
	{
		_objects.push_back(object);
	}

	void Level::addFinish(Finish* finish)
	{
		_finishes.push_back(finish);
	}

	void Level::addProjectile(Projectile* projectile)
	{
		_projectiles.push_back(projectile);
	}

	void Level::addItem(Item* item)
	{
		_items.push_back(item);
	}

	void Level::addMonster(Monster* monster)
	{
		_monsters.push_back(monster);
	}

	void Level::addPipe(Pipe* pipe)
	{
		_pipes.push_back(pipe);
	}

	void Level::addTileset(Tileset* tileset)
	{
		_tilesets.push_back(tileset);
	}

	void Level::addBlockOccurrence(BlockOccurrence* block)
	{
		_blocksOccurrences.push_back(block);
	}

	void Level::loadLevel(string& fileName)
	{
		XMLParser::loadLevel(fileName, this);
	}

	void Level::saveLevel(string& fileName)
	{
		ofstream file(fileName.c_str());
		
		if(file)
		{
			string tabs = "";

			/* Header */
			file << "<?xml version=\"1.0\" ?>" << endl;

			/* Level */
			file << "<level ";
			file << "name=\"" << _name << "\" ";
			file << "width=\"" << _size.x << "\" ";
			file << "heigth=\"" << _size.y << "\" ";
			file << "music=\"" << _musicTitle << "\">" << endl;

			tabs += '\t';

			/* Spawn */
			file << tabs << "<spawn ";
			file << "positionX=\"" << _spawn.x << "\" ";
			file << "positionY=\"" << _spawn.y << "\"/>" << endl;

			/* Checkpoints */
			file << tabs << "<checkpoints";

			if(_checkpoints.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Checkpoint*>::iterator itCheckpoint = _checkpoints.begin();
					itCheckpoint < _checkpoints.end(); ++itCheckpoint)
				{
					(*itCheckpoint)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</checkpoints>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Backgrounds */
			file << tabs << "<backgrounds";

			if(_backgrounds.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Background*>::iterator itBackgrounds = _backgrounds.begin();
					itBackgrounds < _backgrounds.end(); ++itBackgrounds)
				{
					(*itBackgrounds)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</backgrounds>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Foregrounds */
			file << tabs << "<foregrounds";

			if(_foregrounds.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Foreground*>::iterator itForeground = _foregrounds.begin();
					itForeground < _foregrounds.end(); ++itForeground)
				{
					(*itForeground)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</foregrounds>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Objects */
			file << tabs << "<objects";

			if(_foregrounds.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Object*>::iterator itObject = _objects.begin();
					itObject < _objects.end(); ++itObject)
				{
					(*itObject)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</objects>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Finishes */
			file << tabs << "<finishes";

			if(_finishes.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Finish*>::iterator itFinish = _finishes.begin();
					itFinish < _finishes.end(); ++itFinish)
				{
					(*itFinish)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</finishes>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Projectiles */
			file << tabs << "<projectiles";

			if(_projectiles.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Projectile*>::iterator itProjectile = _projectiles.begin();
					itProjectile < _projectiles.end(); ++itProjectile)
				{
					(*itProjectile)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</projectiles>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Items */
			file << tabs << "<items";

			if(_items.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Item*>::iterator itItem = _items.begin();
					itItem < _items.end(); ++itItem)
				{
					(*itItem)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</items>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Monsters */
			file << tabs << "<monsters";

			if(_monsters.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Monster*>::iterator itMonster = _monsters.begin();
					itMonster < _monsters.end(); ++itMonster)
				{
					Monster* monster = (*itMonster);
					WalkingMonster* walkingMonster = dynamic_cast<WalkingMonster*>(monster);
					FlyingMonster* flyingMonster = dynamic_cast<FlyingMonster*>(monster);
					ShellMonster* shellMonster = dynamic_cast<ShellMonster*>(monster);
					
					if(walkingMonster != nullptr)
						walkingMonster->serialize(file, tabs);
					else if(flyingMonster != nullptr)
						flyingMonster->serialize(file, tabs);
					else if(shellMonster != nullptr)
						shellMonster->serialize(file, tabs);
				}

				//tabs.pop_back();
				file << tabs << "</monsters>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Pipes */
			file << tabs << "<pipes";

			if(_pipes.size() > 0)
			{
				file << ">" << endl;
				tabs += '\t';
				for(vector<Pipe*>::iterator itPipe = _pipes.begin();
					itPipe < _pipes.end(); ++itPipe)
				{
					(*itPipe)->serialize(file, tabs);
				}
				//tabs.pop_back();
				file << tabs << "</pipes>" << endl;
			}
			else
			{
				file << "/>" << endl;
			}

			/* Blocks */
			file << tabs << "<tilesets>" << endl;
			if(_tilesets.size() > 0)
			{
				tabs += '\t';
				for(vector<Tileset*>::iterator itTileset = _tilesets.begin();
					itTileset < _tilesets.end(); ++itTileset)
				{
					(*itTileset)->serialize(file, tabs);
				}
				//tabs.pop_back();
			}
			else
			{
				file << "/>" << endl;
			}
			file << tabs << "</tilesets>" << endl;



			file << "</level>" << endl;

		}
	}

	void Level::updatePhysicData(RenderWindow& app)
	{
		/* Items */
		for(vector<Item*>::iterator itItems = this->_items.begin(); itItems != this->_items.end(); ++itItems)
		{
			(*itItems)->updatePhysicData(app);
		}

		/* Monsters */
		for(vector<Monster*>::iterator itMonsters = this->_monsters.begin(); itMonsters != this->_monsters.end(); ++itMonsters)
		{
			(*itMonsters)->updatePhysicData(app);
		}

		/* Projectiles */
		for(vector<Projectile*>::iterator itProjectiles = this->_projectiles.begin(); itProjectiles != this->_projectiles.end(); ++itProjectiles)
		{
			(*itProjectiles)->updatePhysicData(app);
		}
		
		/* Pipes */
		for(vector<Pipe*>::iterator itPipes = this->_pipes.begin(); itPipes != this->_pipes.end(); ++itPipes)
		{
			(*itPipes)->updatePhysicData(app);
		}

		/* BlockOccurence */
		for(vector<BlockOccurrence*>::iterator itBlockOccurrence = this->_blocksOccurrences.begin(); itBlockOccurrence != this->_blocksOccurrences.end(); ++itBlockOccurrence)
		{
			(*itBlockOccurrence)->updatePhysicData(app);
		}
	}

	void Level::updateGraphicData(RenderWindow& app)
	{
		/* Backgrounds */
		for(vector<Background*>::iterator itBackgrounds = this->_backgrounds.begin(); itBackgrounds != this->_backgrounds.end(); ++itBackgrounds)
		{
			(*itBackgrounds)->updateGraphicData(app);
		}

		/* Foregrounds */
		for(vector<Foreground*>::iterator itForegrounds = this->_foregrounds.begin(); itForegrounds != this->_foregrounds.end(); ++itForegrounds)
		{
			(*itForegrounds)->updateGraphicData(app);
		}

		/* Items */
		for(vector<Item*>::iterator itItems = this->_items.begin(); itItems != this->_items.end(); ++itItems)
		{
			(*itItems)->updateGraphicData(app);
		}

		/* Monsters */
		for(vector<Monster*>::iterator itMonsters = this->_monsters.begin(); itMonsters != this->_monsters.end(); ++itMonsters)
		{
			(*itMonsters)->updateGraphicData(app);
		}

		/* Projectiles */
		for(vector<Projectile*>::iterator itProjectiles = this->_projectiles.begin(); itProjectiles != this->_projectiles.end(); ++itProjectiles)
		{
			(*itProjectiles)->updateGraphicData(app);
		}
		
		/* Pipes */
		for(vector<Pipe*>::iterator itPipes = this->_pipes.begin(); itPipes != this->_pipes.end(); ++itPipes)
		{
			(*itPipes)->updateGraphicData(app);
		}

		/* Checkpoint */
		for(vector<Checkpoint*>::iterator itCheckpoints = this->_checkpoints.begin(); itCheckpoints != this->_checkpoints.end(); ++itCheckpoints)
		{
			(*itCheckpoints)->updateGraphicData(app);
		}

		/* BlockOccurence */
		for(vector<BlockOccurrence*>::iterator itBlockOccurrence = this->_blocksOccurrences.begin(); itBlockOccurrence != this->_blocksOccurrences.end(); ++itBlockOccurrence)
		{
			(*itBlockOccurrence)->updateGraphicData(app);
		}
	}

	void Level::render(RenderWindow& app)
	{
		// background_generators ?

		/* Backgrounds */
		for(vector<Background*>::iterator itBackgrounds = this->_backgrounds.begin(); itBackgrounds != this->_backgrounds.end(); ++itBackgrounds)
		{
			(*itBackgrounds)->render(app);
		}

		/* Objects */
		for(vector<Object*>::iterator itObjects = this->_objects.begin(); itObjects != this->_objects.end(); ++itObjects)
		{
			(*itObjects)->render(app);
		}
		
		/* Finish */
		for(vector<Finish*>::iterator itFinish = this->_finishes.begin(); itFinish != this->_finishes.end(); ++itFinish)
		{
			(*itFinish)->render(app);
		}

		/* Items */
		for(vector<Item*>::iterator itItems = this->_items.begin(); itItems != this->_items.end(); ++itItems)
		{
			(*itItems)->render(app);
		}

		/* Blocks */
		for(vector<BlockOccurrence*>::iterator itBlocksOccurrences = this->_blocksOccurrences.begin(); itBlocksOccurrences != this->_blocksOccurrences.end(); ++itBlocksOccurrences)
		{
			(*itBlocksOccurrences)->render(app);
		}

		/* CheckPoints */
		for(vector<Checkpoint*>::iterator itCheckpoints = this->_checkpoints.begin(); itCheckpoints != this->_checkpoints.end(); ++itCheckpoints)
		{
			(*itCheckpoints)->render(app);
		}

		/* Monsters */
		for(vector<Monster*>::iterator itMonsters = this->_monsters.begin(); itMonsters != this->_monsters.end(); ++itMonsters)
		{
			//(*itMonsters)->render(app);
		}

		/* Projectiles */
		for(vector<Projectile*>::iterator itProjectiles = this->_projectiles.begin(); itProjectiles != this->_projectiles.end(); ++itProjectiles)
		{
			(*itProjectiles)->render(app);
		}
		
		/* Pipes */
		for(vector<Pipe*>::iterator itPipes = this->_pipes.begin(); itPipes != this->_pipes.end(); ++itPipes)
		{
			(*itPipes)->render(app);
		}

		// foreground_generators ?

		/* Foregrounds */
		for(vector<Foreground*>::iterator itForegrounds = this->_foregrounds.begin(); itForegrounds != this->_foregrounds.end(); ++itForegrounds)
		{
			(*itForegrounds)->render(app);
		}
	}

    Level::~Level()
    {
		/* Iterators Declarations */
		vector<Background*>::iterator itBackgrounds;
		vector<Object*>::iterator itObjects;
		vector<Finish*>::iterator itFinish;
		vector<Item*>::iterator itItems;
		vector<Checkpoint*>::iterator itCheckpoints;
		vector<Monster*>::iterator itMonsters;
		vector<Projectile*>::iterator itProjectiles;
		vector<Pipe*>::iterator itPipes;
		vector<Foreground*>::iterator itForegrounds;

		// background_generators ?

		/* Backgrounds */
		for(itBackgrounds = this->_backgrounds.begin(); itBackgrounds != this->_backgrounds.end(); ++itBackgrounds)
		{
			delete (*itBackgrounds);
		}

		/* Objects */
		for(itObjects = this->_objects.begin(); itObjects != this->_objects.end(); ++itObjects)
		{
			delete (*itObjects);
		}
		
		/* Finish */
		for(itFinish = this->_finishes.begin(); itFinish != this->_finishes.end(); ++itFinish)
		{
			delete (*itFinish);
		}

		/* Items */
		for(itItems = this->_items.begin(); itItems != this->_items.end(); ++itItems)
		{
			delete (*itItems);
		}

		// BLOCKS 

		/* CheckPoints */
		for(itCheckpoints = this->_checkpoints.begin(); itCheckpoints != this->_checkpoints.end(); itCheckpoints)
		{
			delete (*itCheckpoints);
		}

		/* Monsters */
		for(itMonsters = this->_monsters.begin(); itMonsters != this->_monsters.end(); ++itMonsters)
		{
			delete (*itMonsters);
		}

		/* Projectiles */
		for(itProjectiles = this->_projectiles.begin(); itProjectiles != this->_projectiles.end(); ++itProjectiles)
		{
			delete (*itProjectiles);
		}

		// Persos ??
		
		/* Pipes */
		for(itPipes = this->_pipes.begin(); itPipes != this->_pipes.end(); ++itPipes)
		{
			delete (*itPipes);
		}

		/* Foregrounds */
		for(itForegrounds = this->_foregrounds.begin(); itForegrounds != this->_foregrounds.end(); ++itForegrounds)
		{
			delete (*itForegrounds);
		}

		// foreground_generators ?

    }
} // namespace

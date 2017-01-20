package com.psl.util;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

import com.psl.bean.Dish;
import com.psl.bean.Location;
import com.psl.bean.Order;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DominozPizzaDeliveryImpl implements DominozPizzaDelivery {

    @Override
    public void populateData(String dishFile, String locationFile, List<Dish> dishes, Set<Location> locations) {
        BufferedReader in;
        String line = "";
        try {
            in = new BufferedReader(new FileReader(dishFile));
            while ((line = in.readLine()) != null) {
                String[] dishData = line.split(",");
                Dish dish = new Dish();
                dish.setDishId(Integer.parseInt(dishData[0]));
                dish.setDishName(dishData[1]);
                dish.setCost(Double.parseDouble(dishData[2]));
                dish.setTimeToCook(Double.parseDouble(dishData[3]));
                dishes.add(dish);
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DominozPizzaDeliveryImpl.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(DominozPizzaDeliveryImpl.class.getName()).log(Level.SEVERE, null, ex);
        }

        try {
            in = new BufferedReader(new FileReader(locationFile));
            while ((line = in.readLine()) != null) {
                String[] locationData = line.split(",");
                Location location = new Location();
                location.setLocationCode(Integer.parseInt(locationData[0]));
                location.setLocationDistance(Integer.parseInt(locationData[1]));
                location.setLocationTime(Double.parseDouble(locationData[2]));
                locations.add(location);
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DominozPizzaDeliveryImpl.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(DominozPizzaDeliveryImpl.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    @Override
    public void calculateLocationForDistance(List<Dish> dishes, Set<Location> locations) {
        for (Dish dish : dishes) {
            Set<Location> locationSet = new HashSet<>();
            for (Location location : locations) {
                if (dish.getTimeToCook() + location.getLocationTime() < 30) {
                    locationSet.add(location);
                }
            }
            dish.setSet(locations);
        }
    }

    @Override
    public List<Order> calculateOrder(String orderFile, List<Dish> dishes, Set<Location> locations) {
        List<Order> toPrepare = new ArrayList<>();
        BufferedReader in;
        String line = "";
        try {
            in = new BufferedReader(new FileReader(orderFile));
            while ((line = in.readLine()) != null) {
                String[] orderData = line.split(",");
                int dishId = Integer.parseInt(orderData[0]);
                int locationId = Integer.parseInt(orderData[1]);
                for (Dish dish : dishes) {
                    if (dish.getDishId() == dishId) {
                        for (Location location : locations) {
                            if (location.getLocationCode() == locationId) {
                                if (dish.getTimeToCook() + location.getLocationTime() <= 30) {
                                    Order order = new Order();
                                    order.setDishId(dishId);
                                    order.setLocationCode(locationId);
                                    order.setTotalCost(dish.getCost() + location.getLocationDistance());
                                    toPrepare.add(order);
                                }
                            }
                        }
                    }
                }
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DominozPizzaDeliveryImpl.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            return toPrepare;
        }
    }

    @Override
    public void freeDelivery(List<Order> orders, List<Dish> dishes, Set<Location> locations) {
        for (Order order : orders) {
            for (Location location : locations) {
                if (order.getLocationCode() == location.getLocationCode()) {
                    if (location.getLocationDistance() < 10 && order.getTotalCost() > 200) {
                        order.setTotalCost(order.getTotalCost() - location.getLocationDistance());
                    }
                }
            }
        }
    }

}

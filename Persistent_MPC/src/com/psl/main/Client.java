package com.psl.main;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.psl.bean.Dish;
import com.psl.bean.Location;
import com.psl.bean.Order;
import com.psl.util.DominozPizzaDelivery;
import com.psl.util.DominozPizzaDeliveryImpl;

public class Client {

    public static void main(String[] args) {
        DominozPizzaDelivery dominos = new DominozPizzaDeliveryImpl();
        List<Dish> dishes = new ArrayList<Dish>();
        Set<Location> locations = new HashSet<>();
        dominos.populateData("C:\\Users\\Rupali\\Documents\\NetBeansProjects\\PersistentShit\\dish.txt", "C:\\Users\\Rupali\\Documents\\NetBeansProjects\\PersistentShit\\location.txt", dishes, locations);
        dominos.calculateLocationForDistance(dishes, locations);
        List<Order> toPrepare = dominos.calculateOrder("C:\\Users\\Rupali\\Documents\\NetBeansProjects\\PersistentShit\\order.txt", dishes, locations);
        dominos.freeDelivery(toPrepare, dishes, locations);
        for (Order order : toPrepare) {
            String name = "";
            double dish_cost = 0;
            for (Dish dish : dishes) {
                if (order.getDishId() == dish.getDishId()) {
                    name = dish.getDishName();
                    dish_cost = dish.getCost();
                }
            }
            int distance = 0;
            for (Location location : locations) {
                if (order.getLocationCode() == location.getLocationCode()) {
                    distance = location.getLocationDistance();
                }
            }
            System.out.println(name + " " + dish_cost + " " + distance + " " + order.getTotalCost());
        }
    }

}
